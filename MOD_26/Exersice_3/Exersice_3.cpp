#include <iostream>
#include <vector>
#include <string>

class Window
{
    int x, y;
    int width, height;
public:
    Window(int w, int h) : x(0), y(0), width(w), height(h) {}

    void setPosition(int newX, int newY) { x = newX; y = newY; }
    void setSize(int w, int h) { width = w; height = h; }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void printInfo() const
    {
        std::cout << "Окно: позиция (" << x << ", " << y
            << "), размер " << width << " x " << height << "\n";
    }
};


class Monitor
{
    int width, height;
    std::vector<Window> windows;
public:
    Monitor(int w, int h) : width(w), height(h) {}

    void addWindow(const Window& w)
    {
        windows.push_back(w);
    }

    void moveWindow(int index, int dx, int dy)
    {
        if (index < 0 || index >= (int)windows.size()) return;
        auto& win = windows[index];

        int newX = win.getX() + dx;
        int newY = win.getY() + dy;

        if (newX < 0) newX = 0;
        if (newY < 0) newY = 0;
        if (newX + win.getWidth() > width) newX = width - win.getWidth();
        if (newY + win.getHeight() > height) newY = height - win.getHeight();

        win.setPosition(newX, newY);
        std::cout << "Окно перемещено: (" << newX << ", " << newY << ")\n";
    }

    void resizeWindow(int index, int w, int h)
    {
        if (index < 0 || index >= (int)windows.size()) return;
        auto& win = windows[index];

        if (w < 1) w = 1;
        if (h < 1) h = 1;

        int newW = w;
        int newH = h;

        if (win.getX() + newW > width) newW = width - win.getX();
        if (win.getY() + newH > height) newH = height - win.getY();

        win.setSize(newW, newH);
        std::cout << "Новый размер: " << newW << " x " << newH << "\n";
    }

    void display() const
    {
        if (windows.empty()) return;
        const auto& win = windows[0];

        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                if (i >= win.getX() && i < win.getX() + win.getWidth() &&
                    j >= win.getY() && j < win.getY() + win.getHeight())
                    std::cout << "1";
                else
                    std::cout << "0";
            }
            std::cout << "\n";
        }
    }
};


int main()
{
    Monitor monitor(80, 50);
    Window w(10, 5);
    monitor.addWindow(w);

    std::string cmd;
    while (true)
    {
        std::cout << "\nВведите команду (move, resize, display, info, close): ";
        std::cin >> cmd;
        if (cmd == "move")
        {
            int dx, dy;
            std::cout << "dx dy: ";
            std::cin >> dx >> dy;
            monitor.moveWindow(0, dx, dy);
        }
        else if (cmd == "resize")
        {
            int nw, nh;
            std::cout << "width height: ";
            std::cin >> nw >> nh;
            monitor.resizeWindow(0, nw, nh);
        }
        else if (cmd == "display")
        {
            monitor.display();
        }
        else if (cmd == "info")
        {
            monitor.display();
        }
        else if (cmd == "close")
        {
            break;
        }
    }
}
