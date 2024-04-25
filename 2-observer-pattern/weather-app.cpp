#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
};

class DisplayElement {
public:
    virtual void display() = 0;
};

class WeatherData : public Subject {
private:
    vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;
public:
    void registerObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() {
        for (Observer* o : observers) {
            o->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    void setMeasurements(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
    }
};

class CurrentConditionsDisplay : public Observer, DisplayElement {
private:
    float temperature;
    float humidity;
    Subject* weatherData;
public:
    CurrentConditionsDisplay(Subject* weatherData) {
        this->weatherData = weatherData;
        weatherData->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure) {
        this->temperature = temperature;
        this->humidity = humidity;
        display();
    }

    void display() {
        cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << endl;
    }
};

int main() {
    WeatherData weatherData;
    CurrentConditionsDisplay currentDisplay(&weatherData);

    weatherData.setMeasurements(80, 65, 30.4);
    weatherData.setMeasurements(82, 70, 29.2);
    weatherData.setMeasurements(78, 90, 29.2);

    return 0;
}