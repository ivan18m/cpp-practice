/**
 * @file diamond.cpp
 * @author Ivan Mercep
 * @brief 
 * Example of the Diamond pattern in C++
 * Diamond problem (multiple inheritence)
 * =======================================
 *              Vehicle
 *               /   \
 *              /     \
 *          EngineV   RoadV
 *              \     /
 *               \   /
 *                Car
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

/**
 * @brief Base class
 * 
 */
class Vehicle 
{
public:
    Vehicle() 
    {
        std::cout << "Vehicle constructed\n";
    }
    virtual ~Vehicle() 
    {
        std::cout << "Vehicle destroyed\n";
    }
    virtual void start() = 0; // pure virtual (abstract class, cannot create an object)
};


/**
 * @brief Derived class
 * 
 */
class EngineVehicle: virtual Vehicle 
{
protected:
    int horsePower;

public:
    EngineVehicle(int horsePower): horsePower(horsePower)
    {
        std::cout << "Engine V constructed\n";
    };
    virtual ~EngineVehicle() 
    {
        std::cout << "Engine V destroyed\n";
    }

    virtual void start()
    {
        std::cout << "Starting Engine V\n";
    };
    void makeSound() 
    {
        std::cout << "BRRRRM\n";
    }
};

/**
 * @brief Derived class
 * 
 */
class RoadVehicle: virtual Vehicle 
{
protected:
    int numOfWheels;

public:
    RoadVehicle(int numOfWheels): numOfWheels(numOfWheels)
    {
        std::cout << "Road V constructed\n";
    };
    virtual ~RoadVehicle() 
    {
        std::cout << "Road V destroyed\n";
    }

    virtual void start() 
    {
        std::cout << "Starting Road V\n";
    };
};

/**
 * @brief 
 * Derived class of 2 derived classes who have the same base class
 * 
 */
class Car: virtual EngineVehicle, RoadVehicle 
{
public:
    Car(int numOfWheels, int horsePower): RoadVehicle(numOfWheels), EngineVehicle(horsePower)
    {
        std::cout << "Car constructed\n";
    };
    ~Car() 
    {
        std::cout << "Car destroyed\n";
    }

    /**
     * @brief Facade
     * 
     */
    void start() {
        std::cout << "\nCar Started\n";
        std::cout << "Wheels: " << numOfWheels << "\n";
        std::cout << "HP: " << horsePower << "\n";
        EngineVehicle::makeSound();
        std::cout << "\n";
    }
};


int main(int argc, char** argv) 
{
    Car myCar(4, 200);
    myCar.start();
    
    return 0;
}