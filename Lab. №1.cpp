#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class track
{
private:
    int track_number;
    double max_depth;
    double length;
    double width;
    bool required_skill;
    int required_min_age;
    int required_max_age;
    int people_amount;
    int max_people_amount;
public:
    track()
    {
        track_number = 0;
        max_depth = 0;
        length = 0;
        width = 0;
        required_skill = false;
        required_min_age = 0;
        required_max_age = 0;
        people_amount = 0;
        max_people_amount = 0;
    }

    track(int _track_number, double _max_depth, double _length, double _width, bool _required_skill, int _required_min_age, int _required_max_age, int _people_amount, int _max_people_amount)
    {
        track_number = _track_number;
        max_depth = _max_depth;
        length = _length;
        width = _width;
        required_skill = _required_skill;
        required_min_age = _required_min_age;
        required_max_age = _required_max_age;
        people_amount = _people_amount;
        max_people_amount = _max_people_amount;
    }

    track(track &object)
    {
        track_number = object.track_number;
        max_depth = object.max_depth;
        length = object.length;
        width = object.width;
        required_skill = object.required_skill;
        required_min_age = object.required_min_age;
        required_max_age = object.required_max_age;
        people_amount = object.people_amount;
        max_people_amount = object.max_people_amount;
    }

    ~track() {}

    int get_track_number() { return track_number; }
    double get_max_depth() { return max_depth; }
    double get_length() { return length; }
    double get_width() { return width; }
    bool get_required_skill() { return required_skill; }
    int get_required_min_age() { return required_min_age; }
    int get_required_max_age() { return required_max_age; }
    int get_people_amount() { return people_amount; }
    int get_max_people_amount() { return max_people_amount; }

    void set_track_number(int argument) { track_number = argument; }
    void set_max_depth(double argument) { max_depth = argument; }
    void set_length(double argument) { length = argument; }
    void set_width(double argument) { width = argument; }
    void set_required_skill(bool argument) { required_skill = argument; }
    void set_required_min_age(int argument) { required_min_age = argument; }
    void set_required_max_age(int argument) { required_max_age = argument; }
    void set_people_amount(int argument) { people_amount = argument; }
    void set_max_people_amount(int argument) { max_people_amount = argument; }
    
    void output_track()
    {
        std::cout << "Дорожка №" << track_number << "\nМаксимальная глубина: " << max_depth << "\nДлина: " << length << "\nШирина: " << width << "\nНеобходим навык плаванья" << required_skill << "\nНеобходимый минимальный возраст: " << required_min_age << "\nНеобходимый максимальный возраст: " << required_max_age << "\nКоличество людей на дорожке: " << people_amount << "\nМаксимальное количество людей на дорожке: " << max_people_amount << "\n\n";
    }

    void let_human(bool skill, int age)
    {
        bool complete = false;
        if ((skill == required_skill || skill == true) && (age >= required_min_age && age <= required_max_age) && people_amount < max_people_amount)
        {
            people_amount += 1;
            complete = true;
        }
        if (complete == false)
        {
            std::cout << "Поместить человека на дорожку нельзя.\n";
        }
        else
        {
            std::cout << "Человек помещён на дорожку.\n";
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    track a, b(1, 8.25, 20, 4, true, 14, 70, 2, 4), c(2, 1.50, 7.75, 4, false, 3, 100, 0, 6), d(c);
    a.output_track();
    b.output_track();
    c.output_track();
    d.output_track();
    a.let_human(true, 17);
    d.let_human(true, 20);
    d.let_human(false, 101);
    a.output_track();
    d.output_track();
}