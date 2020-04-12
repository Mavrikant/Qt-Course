#include "rectangle.h"

Rectangle::Rectangle(int length,int width){
    this->length=length;
    this->width=width;
}

void Rectangle::set_length(int length){
    this->length=length;
}

int Rectangle::get_length(){
    return this->length;
}

void Rectangle::set_width(int width){
    this->width=width;
}

int Rectangle::get_width(){
    return this->width;
}

int Rectangle::get_area(){
    return this->length*this->width;
}

int Rectangle::get_perimeter(){
    return 2*(this->length+this->width);

}
