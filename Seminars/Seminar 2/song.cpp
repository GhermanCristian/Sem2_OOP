#include "song.h"

Duration::Duration(int minutes, int seconds) {
	this->minutes = minutes;
	this->seconds = seconds;
}

Song::Song() : artist(""), title(""), duration(Duration(0, 0)) {
	;
}

// duration can also be passed as a const &
Song::Song(const std::string& art, const std::string& t, Duration d) : artist(art), title(t), duration(d) {
	;
}

std::string Song::getArtist() const{
	return this->artist;
}

std::string Song::getTitle() const{
	return this->title;
}
