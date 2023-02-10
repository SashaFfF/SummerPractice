#ifndef WATERQUESTIONNAIRE_H
#define WATERQUESTIONNAIRE_H


class WaterQuestionnaire
{
    int liters;
public:
    WaterQuestionnaire(int amount);
    friend class Recommendation;
};

#endif // WATERQUESTIONNAIRE_H
