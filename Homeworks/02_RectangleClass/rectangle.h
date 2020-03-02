#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
public:
    Rectangle(int length,int width);
    void set_length(int length);
    int get_length();
    void set_width(int width);
    int get_width();
    int get_area();
    int get_perimeter();

private:
    unsigned int length;
    unsigned int width;
};

#endif // RECTANGLE_H
