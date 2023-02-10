#ifndef PHYSICALQUESTIONNAIRE_H
#define PHYSICALQUESTIONNAIRE_H


class PhysicalQuestionnaire
{
    double physicalActivityCoefficient;

public:
    PhysicalQuestionnaire(double PAC);
    friend class Recommendation;
};

#endif // PHYSICALQUESTIONNAIRE_H
