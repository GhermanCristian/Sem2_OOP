#pragma once

#include <string>

// we could've had using namespace std, but those are used in .cpp, not .h

class Duration {
	private:
		int minutes;
		int seconds;
	public:
		Duration(int minutes = 0, int seconds = 0);
};

class Song {
	private:
		std::string artist;
		std::string title;
		Duration duration;
	public:
		Song();
		Song(const std::string& artist, const std::string& title, Duration duration);
		std::string getArtist() const;
		std::string getTitle() const;

};