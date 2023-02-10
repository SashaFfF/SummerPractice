#ifndef BASIC_QUESTIONNAIRE_H
#define BASIC_QUESTIONNAIRE_H
#include <QString>


enum Gender
{
    male,
    female
};

class Questionnaire
{
    int weight;
    int height;
    int age;
    Gender gender;
public:
    Questionnaire(int w, int h,int age, Gender g);
    double returnWeight();
    friend class Recommendation;
};

#endif // BASIC_QUESTIONNAIRE_H
