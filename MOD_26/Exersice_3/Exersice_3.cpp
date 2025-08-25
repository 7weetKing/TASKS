#include <iostream>
#include <vector>

class Window 
{
    int x, y;
    int width, height;
    const int maxW = 80, maxH = 50;
public:
    Window(int w, int h) : x(0), y(0), width(w), height(h) {}

    void move(int dx, int dy) 
    {
        x += dx;
        y += dy;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x + width > maxW) x = maxW - width;
        if (y + height > maxH) y = maxH - height;
        std::cout << "Окно перемещено: (" << x << ", " << y << ")\n";
    }

    void resize(int w, int h)
    {
        if (w < 1) w = 1;
        if (h < 1) h = 1;
        if (x + w > maxW) w = maxW - x;
        if (y + h > maxH) h = maxH - y;
        width = w;
        height = h;
        std::cout << "Новый размер: " << width << " x " << height << "\n";
    }

    void display() const 
    {
        for (int j = 0; j < maxH; j++) 
        {
            for (int i = 0; i < maxW; i++) 
            {
                if (i >= x && i < x + width && j >= y && j < y + height)
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
    Window w(10, 5);
    std::string cmd;
    while (true) 
    {
        std::cout << "\nВведите команду (move, resize, display, close): ";
        std::cin >> cmd;
        if (cmd == "move")
        {
            int dx, dy;
            std::cout << "dx dy: ";
            std::cin >> dx >> dy;
            w.move(dx, dy);
        }
        else if (cmd == "resize") 
        {
            int nw, nh;
            std::cout << "width height: ";
            std::cin >> nw >> nh;
            w.resize(nw, nh);
        }
        else if (cmd == "display") 
        {
            w.display();
        }
        else if (cmd == "close")
        {
            break;
        }
    }
}
