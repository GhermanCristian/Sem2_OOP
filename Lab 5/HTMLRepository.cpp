#include "HTMLRepository.h"
#include <iostream>

HTMLRepository::HTMLRepository() : FileRepository() {
	this->filePath = TEMPORARY_HTML_FILE_NAME;
	createFile(this->filePath);
}

HTMLRepository::HTMLRepository(std::string filePath) : FileRepository(filePath) {
	;
}

std::string HTMLRepository::processLine(std::string line){
	int lineLength = line.length();
	int IGNORED_STARTING_CHARACTERS = 7;
	int IGNORED_ENDING_CHARACTERS = 5;

	line = line.substr(IGNORED_STARTING_CHARACTERS, lineLength - IGNORED_STARTING_CHARACTERS);
	// we have removed IGNORED_STARTING_CHARACTERS, so the length get modified as well
	line.erase(lineLength - IGNORED_ENDING_CHARACTERS - IGNORED_STARTING_CHARACTERS, IGNORED_ENDING_CHARACTERS);
	
	return line;
}

std::vector<Victim> HTMLRepository::loadFromFile(){
	std::vector <Victim> allData;
	std::string ignoredContent;
	std::string victimName, placeOfOrigin, victimAge, photographLink;
	std::fstream fileStream(this->filePath, std::fstream::in);

	int IGNORED_LINES_COUNT = 13;
	for (int i = 0; i < IGNORED_LINES_COUNT; i++) {
		// this happens when the file is empty (there is nothing to read => getline 'is' false)
		if (!getline(fileStream, ignoredContent)) {
			return allData;
		}
	}

	while (1) {
		getline(fileStream, ignoredContent); // <tr>
		if (ignoredContent == "\t\t</table>") { // this line marks the end of the table, so we don't have any Victims left to read
			break;
		}

		getline(fileStream, victimName);
		victimName = processLine(victimName);
		getline(fileStream, placeOfOrigin);
		placeOfOrigin = processLine(placeOfOrigin);
		getline(fileStream, victimAge);
		victimAge = processLine(victimAge);
		getline(fileStream, photographLink);
		photographLink = processLine(photographLink);

		allData.push_back(Victim{victimName, placeOfOrigin, stoi(victimAge), photographLink});

		getline(fileStream, ignoredContent); // </tr>
	}

	fileStream.close();
	return allData;
}

void HTMLRepository::saveToFile(const std::vector<Victim>& currentData){
	std::string currentLine;
	std::ofstream out(this->filePath);

	out << "<!DOCTYPE html>\n";
	out << "<html>\n";
	out << "\t<head>\n";
	out << "\t\t<title>Victims</title>\n";
	out << "\t</head>\n";
	out << "\t<body>\n";
	out << "\t\t<table border = \"1\">\n";
	out << "\t\t<tr>\n";
	out << "\t\t\t<td><b>Name</b></td>\n";
	out << "\t\t\t<td><b>Location</b></td>\n";
	out << "\t\t\t<td><b>Age</b></td>\n";
	out << "\t\t\t<td><b>Photo</b></td>\n";
	out << "\t\t</tr>\n";
	for (auto currentVictim : currentData) {
		out << currentVictim.getHTMLRepresentation();
	}
	out << "\t\t</table>\n";
	out << "\t</body>\n";
	out << "</html>";

	out.close();
}

HTMLRepository::~HTMLRepository() {
	if (createdTemporaryFile == true) {
		remove(TEMPORARY_HTML_FILE_NAME.c_str());
	}
}
