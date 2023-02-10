#ifndef SLEEPQUESTIONNAIRE_H
#define SLEEPQUESTIONNAIRE_H


class SleepQuestionnaire
{
    double sleepHours;
    bool goodTime;
public:
    SleepQuestionnaire(double amount, bool gt);
    friend class Recommendation;
};

#endif // SLEEPQUESTIONNAIRE_H
