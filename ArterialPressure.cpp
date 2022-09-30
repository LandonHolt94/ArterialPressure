/*
* This program determines blood pressure levels.
* Author's: Landon Holt, Steven Tran and Michael Mejia
* Class: CSCI-110-70
* Date: May 11th, 2022
*/
#include <iostream>
#include <fstream> // This allows editing of file.
using namespace std;

void BT() {
    cout << string(10, '*') << "Blood Pressure Test " << string(10, '*') << endl; // Separate function for program title.
    }

void BP(int systolic, int diastolic) {
    fstream myFile;
    myFile.open("PatientFile.txt", ios::out); // Open a file in write mode.
    BT();

    if ((systolic >= 70 && systolic <= 90) && (diastolic >= 40 && diastolic <= 60)) {
        myFile << string(10, '-') <<"Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "Your blood pressure is: Low\n"; // Determines that the patient’s blood pressure is low. 
        myFile << "Use more salt and Drink more water\n"; // Recommended for blood pressure type.
        myFile << "Consult a doctor if your blood pressure continues to decrease.\n";
    }
    else if ((systolic >= 90 && systolic <= 120) && (diastolic >= 60 && diastolic <= 80)) {
        myFile << string(10, '-') << "Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "Your blood pressure is: Normal\n"; // Determines the patient’s blood pressure as Normal.
        myFile << "You are fine\n";
    }
    else if ((systolic >= 120 && systolic <= 129) && (diastolic >= 60 && diastolic <= 80)) {
        myFile << string(10, '-') << "Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "Your blood pressure is: Elevated\n"; // Determines Patient’s blood pressure as Elevated.
        myFile << "Eat a healthy diet rich in whole grains, fruits, vegetables and low-fat dairy products\n";// Recommended for blood pressure type.
    }
    else if ((systolic >= 130 && systolic <= 139) || (diastolic >= 80 && diastolic <= 89)) {
        myFile << string(10, '-') << "Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "You have High Blood pressure! (Hypertension Stage 1)\n"; // Determines Patient’s blood pressure as High or (Hypertension Stage 1).
        myFile << "Decrease the salt in your diet And Eat a healthy diet\n"; // Recommended for blood pressure type.
        myFile << "Monitor your blood pressure and consult your doctor.\n";
    }
    else if ((systolic >= 140 && systolic <= 180) || (diastolic >= 90 && diastolic <= 120)) {
        myFile << string(10, '-') << "Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "You have High Blood pressure! (Hypertension Stage 2)\n"; // Determines Patient’s blood pressure as High or (Hypertension Stage 2).
        myFile << "Decrease the salt in your diet And Eat a healthy diet\n"; // Recommended for blood pressure type.
        myFile << "Monitor your blood pressure and consult your doctor.\n";
    }
    else if ((systolic > 180) || (diastolic > 120)) {
        myFile << string(10, '-') << "Recommendations for patient based on blood pressure results:" << string(10, '-') << endl;
        myFile << "Hypertensive Crisis\n"; // Determines that the Patient is having a Hypertensive Crisis.
        myFile << "Immediatly consult your doctor!\n"; // Highly Recommended for blood pressure type.
        myFile << "Like right now, what are you waiting for?!?!\n";
    }
}


int main() {


    int systolic, diastolic, plusepressure;
    float MAP;

    BT();
   
    cout << "Lets check your blood pressure" << endl; // The program Introduction to our project.

    cout << "Enter systolic pressure : "; //Where you can type the systolic pressure.
    cin >> systolic; //Makes the Systolic function activate.

    cout << "Enter diastolic pressure : "; //Where you can type the diastolic pressure.
    cin >> diastolic; //Makes the Diastolic function activate.

    plusepressure = systolic - diastolic;

    cout << "Pulse pressure: " << plusepressure << endl;


    MAP = (2 * (float)(diastolic + systolic)) / 3;

    cout << "MAP: " << MAP << endl;

    cout << "Please refer to Patients File for further recommendation on blood pressure levels." << endl;
   
    BP(systolic, diastolic);
    return 0;
}
