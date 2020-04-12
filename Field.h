//
// Created by ab on 12/04/2020.
//

#ifndef CSNAKE_FIELD_H
#define CSNAKE_FIELD_H


class Field {
public:
    Field();
    Field(int width, int height);
    ~Field();

    int eaten{0};
    [[nodiscard]] int get_width() const;
    [[nodiscard]] int get_height() const;

    void init();


private:
    int width;
    int height;

    void spawn_food();
    void step_snake();
};


#endif //CSNAKE_FIELD_H
