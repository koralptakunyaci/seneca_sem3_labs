// Workshop 7
// Name: Koralp Takunyaci
// ID: 119716207
// Email: ktakunyaci@myseneca.ca
// Date: 20/11/2021

// Section: NAA

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <sstream>
#include <numeric>
#include <string>
#include "SongCollection.h"

namespace sdds 
{
	SongCollection::SongCollection(std::string fileName)
	{
		std::fstream fin(fileName);

		if (!fin)
		{
			throw "An error occured!";
		}

		std::string str;
		Song m_song;

		while (std::getline(fin, str, '\n'))
		{
			m_song.title = str.substr(0, 25);
			m_song.title.erase(m_song.title.find_last_not_of(' ') + 1);
			m_song.title.erase(0, m_song.title.find_first_not_of(' '));
			str.erase(0, 25);

			m_song.artist = str.substr(0, 25);
			m_song.artist.erase(m_song.artist.find_last_not_of(' ') + 1);
			m_song.artist.erase(0, m_song.artist.find_first_not_of(' '));
			str.erase(0, 25);

			m_song.album = str.substr(0, 25);
			m_song.album.erase(m_song.album.find_last_not_of(' ') + 1);
			m_song.album.erase(0, m_song.album.find_first_not_of(' '));
			str.erase(0, 25);

			m_song.releaseYear = str.substr(0, 5);
			m_song.releaseYear.erase(m_song.releaseYear.find_last_not_of(' ') + 1);
			m_song.releaseYear.erase(0, m_song.releaseYear.find_first_not_of(' '));
			str.erase(0, 5);

			m_song.lengthSong = stoi(str.substr(0, 5));
			str.erase(0, 5);

			m_song.m_price = stod(str.substr(0, 5));
			str.erase(0, 5);

			v_song.push_back(m_song);
			
		}

	}
	void SongCollection::sort(const std::string name)
	{
		if (name == "title")
		{
			std::sort(v_song.begin(), v_song.end(), [](Song song1, Song song2)
				{
					return song1.title < song2.title;
				});
		}
		else if (name == "album")
		{
			std::sort(v_song.begin(), v_song.end(), [](Song song1, Song song2)
				{
					return song1.album < song2.album;
				});
		}
		else if (name == "length")
		{
			std::sort(v_song.begin(), v_song.end(), [](Song song1, Song song2)
				{
					return song1.lengthSong < song2.lengthSong;
				});
		}
	}
	void SongCollection::cleanAlbum()
	{
		std::for_each(v_song.begin(), v_song.end(), [](Song& song)
			{
				if (song.album == "[None]")
				{
					song.album = "";
				}
			});
	}
	bool SongCollection::inCollection(const std::string str) const
	{
		bool tempBool = false;
		auto temp = std::find_if(v_song.begin(), v_song.end(), [str](Song tempSong)
			{
				return tempSong.artist == str;
			});
		
		if (temp != v_song.end())
		{
			tempBool = true;
		}
		return tempBool;
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string str) const
	{
		auto songs = std::count_if(v_song.begin(), v_song.end(), [&str](const Song& tempSong)
			{
				return tempSong.artist == str;
			});

		std::list<Song> songList(songs);

		std::copy_if(v_song.begin(), v_song.end(), songList.begin(), [str](Song tempSong)
			{
				return tempSong.artist == str;
			});

		return songList;
	}
	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(v_song.begin(), v_song.end(), [&out](const Song& song)
			{
				out << song << std::endl;
			});

		size_t time = std::accumulate(v_song.begin(), v_song.end(), 0, [](int totalLength, Song song1)
			{
				return totalLength + song1.lengthSong;
			});

		size_t mins = time / 60;

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "|" << std::right << std::setw(78) << std::setfill(' ');
		out << "Total Listening Time: " << std::to_string(mins / 60) << ":" << 
			std::setw(2) << std::setfill('0') << std::to_string(mins % 60) << ":" << 
			std::setw(2) << std::setfill('0') << std::to_string(time % 60) << " |" << std::endl;
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
	
		out << "| " << std::left << std::setw(20) << std::setfill(' ') <<  theSong.title << " | " << 
			std::left << std::setw(15) << std::setfill(' ') <<  theSong.artist << " | " << 
			std::left << std::setw(20) << std::setfill(' ') <<  theSong.album << " | " << 
			std::right << std::setw(6) << std::setfill(' ') <<  theSong.releaseYear << " | " <<
			theSong.lengthSong / 60 << ":" << std::setw(2) << std::setfill('0') << 
			theSong.lengthSong % 60 << std::fixed << std::setprecision(2) << " | " <<
			theSong.m_price << " |";

		return out;
	}

}