//
// Created by ab on 12/04/2020.
//

#include "Field.h"

Field::Field() {
    this->width = 20;
    this->height = 20;
    init();
}

Field::Field(int width, int height) {
    this->width = width;
    this->height = height;
    init();
}

void Field::init() {

}

int Field::get_width() const {
    return width;
}

int Field::get_height() const {
    return height;
}

void Field::spawn_food() {

}

void Field::step_snake() {

}
