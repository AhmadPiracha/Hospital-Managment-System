#include<iostream>

#include<fstream>

#include<string>

#include<iomanip>

#include <ctime>

#include<cmath>

using namespace std;
class Appointment {
protected:
    string Doctor;
    string Department_Name;
    string Appointment_Id;
    string Appointment_Status;
    int Patient_id;
    string Parent_Dept;
    string Appoitment_Time;
public:
    friend class Admin;
    friend class Patient;
    friend class Doctor;
    Appointment();
    friend istream& operator >> (istream& Ain, Appointment& c);
    friend ifstream& operator >> (ifstream& fin, Appointment& c);
    friend ostream& operator << (ostream& Aout, Appointment& c);
    friend ofstream& operator << (ofstream& fout, Appointment& c);
};
class Patient {
private:
    string First_Name;
    string Last_Name;
    string Department_Name;
    string Dental,
        Accident_Emergency,
        Orthopedics,
        Psychiatry,
        Physiotherapy;

    int P_id;
    string Registration_Date;
    string Contact_No;
    string Gender;
    string Blood_Group;
    string Address;
    int Fee_submitted;
    string Qualification;
    int Salary;
    string Email;
    string Password;
    Appointment* A;
    int Total_Fee;
    int patient;
    int noOfAppoint;
    static int Pat_ID;
public:
    friend class Admin;
    friend class Doctor;
    friend class Appointment;
    Patient();
    friend istream& operator >> (istream& Pin, Patient& obj);
    friend ifstream& operator >> (ifstream& fin, Patient& obj);
    friend ostream& operator << (ostream& Pout, Patient obj);
    friend ofstream& operator << (ofstream& fout, Patient obj);
    void CheckfeeStatus();
    void viewAppointments();
    string getPassword();
    void viewFeeStatus();
};
class Doctor : public Appointment {
protected: string First_Name;
         string Last_Name;
         string Department_Name;
         string Dental,
             Accident_Emergency,
             Orthopedics,
             Psychiatry,
             Physiotherapy;
         int D_id;
         string Email;
         string Password;
         int Reg_Date;
         string Gender;
         string Blood;
         string Address;
         string Contact_no;
         string Qualification;
         double Salary;
         Patient* pat;
         int Total_No_Patients;

public: friend class Admin;
      Doctor();
      friend istream& operator >> (istream& Din, Doctor& obj);
      friend ifstream& operator >> (ifstream& fin, Doctor& obj);
      friend ostream& operator << (ostream& Dout, Doctor& obj);
      friend ofstream& operator << (ofstream& fout, Doctor& obj);
      void Doc_Appointments();
      void Appointments(Patient* s, int NoOfstd);
      string getTpassword();

};
class Admin {
protected:
    int noOfDoc;
    int noOfAppo;
    int noOfPatient;
    Doctor* D;
    Appointment* A;
    Patient* P;
public:
    Admin();
    void adddoctor();
    void addPatient();
    void addAppointment();
    void AssignAppointment();
    void editPatient();
    void editDoctor();
    void viewAllPatient();
    void viewAllDoctors();
    void viewAllAppointment();
    void updateAppontment();
    void viewFeeStatus();
    bool checkAppoforPatient(Appointment objP, Appointment* objA, int size);
    bool CheckPatientByEmail(string Email, Patient& patient);
    bool checkDoctorByEmail(string Email, Doctor& doctor);
    Patient* getPatientsForDoctor();
    int getNoPatient();
    ~Admin();
};

void AdminModule(Admin& A);
void PatientModule(Patient& Pa, Admin A);
void DoctorModule(Doctor& Do, Admin A);