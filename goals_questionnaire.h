#ifndef GOALSQUESTIONNAIRE_H
#define GOALSQUESTIONNAIRE_H


enum Goal{
    lose_weight,
    maintain_weight,
};

class GoalsQuestionnaire
{
    Goal goal;
    int weight_difference;
public:
    GoalsQuestionnaire(Goal g, int w = 0);
    int getWeightDifferent();
    friend class Recommendation;
};

#endif // GOALSQUESTIONNAIRE_H
