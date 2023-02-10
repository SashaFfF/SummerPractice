#include "basic_questionnaire.h"

Questionnaire::Questionnaire(int w, int h, int a, Gender g)
{
    weight = w;
    height = h;
    age = a;
    gender = g;
}

double Questionnaire::returnWeight()
{
    return weight;
}
