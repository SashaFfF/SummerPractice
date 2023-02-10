#include "recommendation.h"
#include <QDebug>

Recommendation::Recommendation(Questionnaire *bQ, PhysicalQuestionnaire *pQ, FoodQuestionnaire *fQ,
                               SleepQuestionnaire *sQ, WaterQuestionnaire *wQ, GoalsQuestionnaire *gQ)
{
    basicQuestionnaire = bQ;
    physicQuestionnaire = pQ;
    foodQuestionnaire = fQ;
    sleepQuestionnaire = sQ;
    waterQuestionnaire = wQ;
    goalQuestionnaire = gQ;
    caloriesNorm = (int)calculateNorm();
}

int Recommendation::calculateNorm()
{
    double calories = 0;
    if(basicQuestionnaire->gender == female){
        calories = physicQuestionnaire->physicalActivityCoefficient*(10*basicQuestionnaire->weight + 6.25*basicQuestionnaire->height -
                                                                   5*basicQuestionnaire->age - 161);
    }
    else if (basicQuestionnaire->gender == male){
        calories = physicQuestionnaire->physicalActivityCoefficient*(10*basicQuestionnaire->weight + 6.25*basicQuestionnaire->height -
                                                 5*basicQuestionnaire->age + 5);
    }
    return  (int)calories;
}

double Recommendation::calculateBodyMassIndex()
{
    double index = 10000*basicQuestionnaire->weight / (basicQuestionnaire->height*basicQuestionnaire->height);
    return index;
}

int Recommendation::calculateCaloriesForSlowLoss()
{
    double norm = calculateNorm();
    double slowNorm = 0.8*norm;
    return (int)slowNorm;
}

int Recommendation::calculateCaloriesForFastLoss()
{
    double norm = calculateNorm();
    int FastNorm =0.6*norm;
    if (FastNorm<1000) FastNorm=1000;
    return FastNorm;
}

double Recommendation::calculateWaterNorm()
{
    return basicQuestionnaire->weight*0.035;
}

QString Recommendation::getBodyMassIndexRecommendation()
{
    double index=calculateBodyMassIndex();
    int strNumber;
    if (index<=16) strNumber=1;
    else if (index>16 && index<=18.5)strNumber=2;
    else if (index>18.5 && index<=25)strNumber=3;
    else if (index>25 && index<=30)strNumber=4;
    else if (index>30 && index<=35)strNumber=5;
    else if (index>35 && index<=40)strNumber=6;
    else strNumber=7;
    int i=1;
    QFile MyFile("C://Users//user//Documents//practice//recommendation.txt");
    MyFile.open(QIODevice::ReadOnly);
    if(MyFile.isOpen())
    {
    qDebug() << "File is open";
    }
    QTextStream in (&MyFile);
    QString line;
    do {
        line = in.readLine();
        if (strNumber==i) {
            MyFile.close();
            return line;
        }
        i++;
    } while (!line.isNull());
    MyFile.close();
    return "";
}

QString Recommendation::getPhActivityRecommendation()
{
    int strNumber;
    double index = physicQuestionnaire->physicalActivityCoefficient;
    if (index==1.2 || index==1.375) strNumber=8;
    else strNumber=9;
    int i=1;
    QFile MyFile("C://Users//user//Documents//practice//recommendation.txt");
    MyFile.open(QIODevice::ReadOnly);
    QTextStream in (&MyFile);
    QString line;
    do {
        line = in.readLine();
        if (strNumber==i) {
             MyFile.close();
            return line;
        }
        i++;
    } while (!line.isNull());
    MyFile.close();
    return "";

}

QString Recommendation::getFoodRecommedation()
{
    QString foodList = "Мы советуем вам добавить в свой рацион следующие продукты : \n";
bool cheking=true;
    QFile MyFile("C://Users//user//Documents//practice//recommendation.txt");
    MyFile.open(QIODevice::ReadOnly);
    if(MyFile.isOpen())
    {
    qDebug() << "File is open";
    }
    QTextStream in (&MyFile);
    QString line;
    int i = 0;
    int count = 1;
    for (int k = 1; k < 18; k++){
         line = in.readLine();
    }
    do {
        line = in.readLine();
        if (foodQuestionnaire->food[i]==nothing) {
            cheking=false;
             foodList+=QString::number(count) + ". " + line +"\n";
             count++;
        }
        i++;
    } while (i!=18);
    MyFile.close();
    if(!cheking){
        return foodList;
    } else{
        return "У вас прекрасный рацион";
    }

}

QString Recommendation::getSleepRecommendation()
{
    int index;
    if(sleepQuestionnaire->goodTime){
        index = 14;
    }
    else{
        index = 13;
    }
    int index2;
    if(sleepQuestionnaire->sleepHours == 7.5 || sleepQuestionnaire->sleepHours == 8.5){
        index2 = 16;
    }
    else if(sleepQuestionnaire->sleepHours == 6.5 || sleepQuestionnaire->sleepHours == 5.5){
        index2 = 15;
    }
    else{
        index2 = 17;
    }

    QFile MyFile("C://Users//user//Documents//practice//recommendation.txt");
    MyFile.open(QIODevice::ReadOnly);
    QTextStream in (&MyFile);
    QString line;
    QString resultStr = "";
    int i = 1;
    do {
        line = in.readLine();
        if (index==i) {
            resultStr += line + "\n";
        }
        if (index2 == i) {
            resultStr += line;
        }
        i++;
    } while (!line.isNull());

    MyFile.close();
    return resultStr;
}

Goal Recommendation::getGoal()
{
    return goalQuestionnaire->goal;
}

int Recommendation::getAmountOfDays(bool slow, int countKg)
{
    if(slow){
        return countKg * 7700 / (calculateNorm()-calculateCaloriesForSlowLoss());
    }
    else {
        return countKg * 7700 / (calculateNorm()-calculateCaloriesForFastLoss());
    }

}

QString Recommendation::getWaterRecommendation()
{
    int waterNorm = calculateWaterNorm();
    int strNumber;
    if(waterNorm>waterQuestionnaire->liters-0.25){
        strNumber = 10;
    }
    else if (waterNorm >= waterQuestionnaire->liters - 0.25 && waterNorm <= waterQuestionnaire->liters + 0.25 ){
        strNumber = 11;
    }
    else {
        strNumber = 12;
    }
    QFile MyFile("C://Users//user//Documents//practice//recommendation.txt");
    MyFile.open(QIODevice::ReadOnly);
    int i = 1;
    if(MyFile.isOpen())
    {
    qDebug() << "File is open";
    }
    QTextStream in (&MyFile);
    QString line;
    do {
        line = in.readLine();
        if (strNumber==i) {
             MyFile.close();
            return line;
        }
        i++;
    } while (!line.isNull());
    MyFile.close();
    return " ";
}

