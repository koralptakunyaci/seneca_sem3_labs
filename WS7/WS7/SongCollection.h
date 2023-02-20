// Workshop 7
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 20/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <vector>


namespace sdds
{
	struct Song
	{
		std::string artist;
		std::string title;
		std::string album;
		double m_price;
		std::string releaseYear;
		size_t lengthSong;
		/*size_t seconds = lengthSong % 60;*/
	}; 

	class SongCollection
	{
		std::vector<Song> v_song;
	public:
		SongCollection(std::string fileName);
		void display(std::ostream& out) const;
		void sort(std::string name);
		void cleanAlbum();
		bool inCollection(const std::string str) const;
		std::list<Song> getSongsForArtist(const std::string str) const;


	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
		
}



#endif // !SDDS_SONGCOLLECTION_H
