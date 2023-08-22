/*
Name: Eric Jo
Student number: 137057188
Email: hjo9@myseneca.ca
Completion date: June 8 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

double pi = 3.14159265;
namespace sdds {
    

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && m_usable == true) {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
        else {

        }
        
    }

    bool Canister::isEmpty()const {
        if (m_contentVolume < 0.00001) {
            return true;
        }
        return false;
    }

    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName == nullptr || C.m_contentName == nullptr) {
            return false;
        }
        if (strCmp(m_contentName, C.m_contentName)) {
            return true;
        }
        
        return true;
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter,
        const char* contentName) {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }
    Canister::~Canister() {
        delete[] m_contentName;
    }

    Canister& Canister::setContent(const char* contentName){
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (strCmp(m_contentName, contentName) != 0) {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(double quantity){
        if (m_usable && quantity > 0 && quantity + volume() <= capacity()) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C){
        setContent(C.m_contentName);
        if (C.volume() > capacity() - volume()) {
            C.m_contentVolume -= capacity() - volume();
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    double Canister::volume()const{
        return m_contentVolume;
    }

    std::ostream& Canister::display()const{
        cout.precision(1);
        cout.setf(ios::fixed);
        cout.width(7);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

        if (m_usable == false) {
            cout << " of Unusable content, discard!";
        }
        else if(m_contentName != nullptr) {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << m_contentName;
        }
        return cout;
    }

    double Canister::capacity()const {
        return pi * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}