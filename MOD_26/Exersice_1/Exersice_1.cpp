#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Track 
{
    std::string title;
    std::tm creationDate{};
    int duration;
public:
    Track(const std::string& t, const std::tm& d, int dur)
        : title(t), creationDate(d), duration(dur) {}

    std::string getTitle() const { return title; }

    void printInfo() const
    {
        std::cout << "Название: " << title << "\n";
        std::cout << "Дата: " << creationDate.tm_mday << "."
            << creationDate.tm_mon + 1 << "."
            << creationDate.tm_year + 1900 << "\n";
        std::cout << "Длительность: " << duration << " секунд\n";
    }
};

class Player 
{
    std::vector<Track> tracks;
    bool isPlaying = false;
    bool isPaused = false;
    int currentIndex = -1;
public:
    void addTrack(const Track& t) 
    {
        tracks.push_back(t);
    }

    void play(const std::string& name) 
    {
        if (isPlaying) 
        {
            std::cout << "Уже воспроизводится трек.\n";
            return;
        }
        for (size_t i = 0; i < tracks.size(); ++i) 
        {
            if (tracks[i].getTitle() == name) 
            {
                currentIndex = i;
                isPlaying = true;
                isPaused = false;
                std::cout << "Воспроизведение:\n";
                tracks[i].printInfo();
                return;
            }
        }
        std::cout << "Трек не найден.\n";
    }

    void pause() 
    {
        if (isPlaying && !isPaused)
        {
            isPaused = true;
            std::cout << "Трек поставлен на паузу.\n";
        }
    }

    void stop() 
    {
        if (isPlaying) 
        {
            isPlaying = false;
            isPaused = false;
            std::cout << "Воспроизведение остановлено.\n";
        }
    }

    void next() 
    {
        if (tracks.empty()) return;
        currentIndex = rand() % tracks.size();
        isPlaying = true;
        isPaused = false;
        std::cout << "Следующий трек:\n";
        tracks[currentIndex].printInfo();
    }
};

int main() 
{
    srand(time(0));

    Player p;
    std::tm date{};
    date.tm_year = 122;
    date.tm_mon = 5;
    date.tm_mday = 15;
    p.addTrack(Track("Song1", date, 180));
    p.addTrack(Track("Song2", date, 200));
    p.addTrack(Track("Song3", date, 240));

    std::string cmd;
    while (true) 
    {
        std::cout << "\nВведите команду (play, pause, next, stop, exit): ";
        std::cin >> cmd;
        if (cmd == "play") 
        {
            std::string name;
            std::cout << "Название трека: ";
            std::cin >> name;
            p.play(name);
        }
        else if (cmd == "pause") 
        {
            p.pause();
        }
        else if (cmd == "next") 
        {
            p.next();
        }
        else if (cmd == "stop")
        {
            p.stop();
        }
        else if (cmd == "exit")
        {
            break;
        }
    }
}
