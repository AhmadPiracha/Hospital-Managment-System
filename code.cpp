#include"Header.h";

int Patient::Pat_ID = 0;

//Main function
void AdminModule(Admin& A) {
    int Select;
    do {
        cout << "\n\n\n\n\n\n";

        cout << "\n\t\t\tWelcome to Admin Module\n";
        cout << "\t\t\t01)  Add a New Doctor\n";
        cout << "\t\t\t02)  Add a New Patient\n";
        cout << "\t\t\t03)  Add a New Appointment\n";
        cout << "\t\t\t04)  Assingn an Appointment\n";
        cout << "\t\t\t05)  Edit Doctor Detail\n";
        cout << "\t\t\t06)  Edit Patient Detail\n";
        cout << "\t\t\t07)  View all Patient Detail\n";
        cout << "\t\t\t08)  View all Doctor Detail\n";
        cout << "\t\t\t09)  View all Appointment Detail\n";
        cout << "\t\t\t10)  update Patient Marks\n";
        cout << "\t\t\t11)  View Fee Status of all Patients\n";
        cout << "\t\t\t12)  Exit\n\n";
        cout << "Enter Your Choice\t=";

        cin >> Select;
        switch (Select) {
        case 1:
            A.adddoctor();

            break;
        case 2:
            A.addPatient();

            break;
        case 3:
            A.addAppointment();
            break;
        case 4:
            A.AssignAppointment();
            break;
        case 5:
            A.editDoctor();
            break;
        case 6:
            A.editPatient();
            break;
        case 7:
            A.viewAllPatient();
            break;
        case 8:
            A.viewAllDoctors();
            break;
        case 9:
            A.viewAllAppointment();
            break;
        case 10:
            A.updateAppontment();
            break;
        case 11:
            A.viewFeeStatus();
            break;
        case 12:
            return;
            break;

        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (1);
}
void PatientModule(Patient& pa, Admin A) {
    string email, password;
    cout << "Enter Your Email/Username...." << endl;
    cin >> email;
    cout << "Enter Your Password...." << endl;
    cin >> password;
    A.CheckPatientByEmail(email, pa);
    if (pa.getPassword() != password) {
        cout << "Invalid Password........" << endl;
        return;
    }
    int choice = 0;
    while (choice != 3) {
        cout << "Enter\n\t1) VIEW APPOINTMENTS \n\t2) VIEW FEE STATUS\n\t3) LOG-OUT\n";
        cin >> choice;
        switch (choice) {
        case 1:
            pa.viewAppointments();
            break;
        case 2:
            pa.viewFeeStatus();
            break;
        default:
            cout << "Invalid input..........." << endl;
        }
    }
}
void DoctorModule(Doctor& Th, Admin A) {
    string email, password;
    cout << "Enter Your Email/Username...." << endl;
    cin >> email;
    cout << "Enter Your Password...." << endl;
    cin >> password;
    A.checkDoctorByEmail(email, Th);
    if (Th.getTpassword() != password) {
        cout << "Invalid Password........" << endl;
        return;
    }
    int choice = 0;
    while (choice != 3) {
        cout << "Enter\n\t1) VIEW DOCTOR APPOINTMENTS\n\t2) UPDATE APPOINTMENTS\n\t3 TO LOG-OUT\n";
        cin >> choice;
        switch (choice) {
        case 1:
            Th.Doc_Appointments();
            break;
        case 2:
            Th.Appointments(A.getPatientsForDoctor(), A.getNoPatient());
            break;
        default:
            cout << "Invalid input..........." << endl;
        }
    }

}

//all funtions or operator overloded in Patient class

Patient::Patient() {
    First_Name = Last_Name = Department_Name = Dental = Accident_Emergency = Orthopedics = Psychiatry = Physiotherapy = Email = Password = Gender = Qualification = Address = " ";
    Fee_submitted = 0;
    noOfAppoint = 0;
    P_id = ++Pat_ID;
}
istream& operator >> (istream& Pin, Patient& obj) {

    cout << "Enter First Name of Patient\t\t\t=";
    Pin >> obj.First_Name;
    cout << "Enter Last Name of Patient \t\t\t=";
    Pin >> obj.Last_Name;
    cout << "Enter Department Name \t\t\t\n";
    cout << "Following are Departments in Our Hospital \n";
    cout << "1) Dental\n";
    cout << "2) Accident & Emergency\n";
    cout << "3) Orthopedics\n";
    cout << "4) Psychiatry\n";
    cout << "5) Physiotherapy\n";
    cout << "Enter the Department you in which you want to take Appointment \n";
    Pin >> obj.Department_Name;
    cout << "Enter ID of Patient\t\t\t=";
    Pin >> obj.P_id;
    cout << "Enter Registration of Patient\t\t\t=";
    Pin >> obj.Registration_Date;
    cout << "Enter Contact No of Patient\t\t\t=";
    Pin >> obj.Contact_No;
    cout << "Enter Gender of Patient\t\t\t=";
    Pin >> obj.Gender;
    cout << "Enter Blood Group of Patient\t\t\t=";
    Pin >> obj.Blood_Group;
    cout << "Enter Address of Patient\t\t\t=";
    Pin >> obj.Address;
    cout << "Enter Fee submitted of Patient(1 for YES / 0 for NO)\t\t\t=";
    Pin >> obj.Fee_submitted;
    cout << "Enter Qualification of Patient\t\t\t=";
    Pin >> obj.Qualification;
    cout << "Enter Salary of Patient\t\t\t=";
    Pin >> obj.Salary;
    cout << "Enter Email of Patient\t\t\t=";
    Pin >> obj.Email;
    cout << "Enter Password of Patient\t\t\t=";
    Pin >> obj.Password;
    cout << "Enter Total Fee of the Patient\t\t\t=";
    Pin >> obj.Total_Fee;
    obj.CheckfeeStatus();
    return Pin;
}
void Patient::CheckfeeStatus() {
    if (this->Fee_submitted > this->Total_Fee) {
        this->Fee_submitted = this->Total_Fee;
    }
}
ifstream& operator >> (ifstream& fin, Patient& obj) {
    fin >> obj.First_Name;
    fin >> obj.Last_Name;
    fin >> obj.Department_Name;
    fin >> obj.P_id;
    fin >> obj.Registration_Date;
    fin >> obj.Contact_No;
    fin >> obj.Gender;
    fin >> obj.Blood_Group;
    fin >> obj.Address;
    fin >> obj.Fee_submitted;
    fin >> obj.Qualification;
    fin >> obj.Salary;
    fin >> obj.Email;
    fin >> obj.Password;
    fin >> obj.Total_Fee;
    fin >> obj.noOfAppoint;
    obj.A = new Appointment[obj.noOfAppoint];
    for (int i = 0; i < obj.noOfAppoint; i++) {
        fin >> obj.A[i];
    }
    return fin;
}
ostream& operator << (ostream& Pout, Patient obj) {
    Pout << setw(5) << " ";
    Pout << setw(12) << left << obj.P_id << setw(8) << obj.First_Name << setw(12) << obj.Last_Name << setw(15) << obj.Department_Name << endl;
    return Pout;
}
ofstream& operator << (ofstream& fout, Patient obj) {
    fout << obj.First_Name << "\t";
    fout << obj.Last_Name << "\t";
    fout << obj.Department_Name << "\t";
    fout << obj.P_id << "\t";
    fout << obj.Registration_Date << "\t";
    fout << obj.Contact_No << "\t";
    fout << obj.Gender << "\t";
    fout << obj.Blood_Group << "\t";
    fout << obj.Address << "\t";
    fout << obj.Fee_submitted << "\t";
    fout << obj.Qualification << "\t";
    fout << obj.Salary << "\t";
    fout << obj.Email << "\t";
    fout << obj.Password << "\t";
    fout << obj.Total_Fee << "\t";
    fout << obj.noOfAppoint << "\n";
    for (int i = 0; i < obj.noOfAppoint; i++) {
        fout << obj.A[i];
    }
    fout << endl;
    return fout;
}
void Patient::viewAppointments() {

    for (int i = 0; i < this->noOfAppoint; i++) {
        cout << "Appointment Status (Checked / Unchecked )= " << this->A->Appointment_Status << endl;
        cout << "Appointment Time = " << this->A[i].Appoitment_Time << endl;

    }
}
string Patient::getPassword() {
    return Password;
}
void Patient::viewFeeStatus() {

    cout << "Name = " << this->First_Name << " " << this->Last_Name << endl;
    cout << "ID No. = " << this->P_id << endl;
    cout << "Fee status = " << this->Fee_submitted << endl;
    cout << "\n\n";

}

//all funtions or operator overloded in Apponintment class
Appointment::Appointment() {
    Appointment_Id = Patient_id = 0;
}
istream& operator >> (istream& Ain, Appointment& c) {
    cout << "Enter Department Name \t=";
    cout << "Following are Departments in Our Hospital \n";
    cout << "1) Dental\n";
    cout << "2) Accident & Emergency\n";
    cout << "3) Orthopedics\n";
    cout << "4) Psychiatry\n";
    cout << "5) Physiotherapy\n";
    cout << "Enter the Department you in which you want to take Appointment \n";

    Ain >> c.Department_Name;
    cout << "Enter Appointment ID \t\t\t=";
    Ain >> c.Appointment_Id;
    cout << "Enter the Patient ID\t=";
    Ain >> c.Patient_id;
    cout << "Enter the Time of Appointment\t=";
    Ain >> c.Appoitment_Time;
    cout << "Enter name of Parent Department\t\t=";
    Ain >> c.Parent_Dept;
    cout << "Enter Appointment Status (Checked / Unchecked ) \t\t\t=";
    Ain >> c.Appointment_Status;

    return Ain;
}
ifstream& operator >> (ifstream& fin, Appointment& c) {
    fin >> c.Department_Name;
    fin >> c.Appointment_Id;
    fin >> c.Patient_id;
    fin >> c.Appoitment_Time;
    fin >> c.Parent_Dept;
    fin >> c.Appointment_Status;
    return fin;
}
ostream& operator << (ostream& Aout, Appointment& c) {
    cout << "The Depqartment Name \t=" << c.Department_Name << endl;
    cout << "The Appointment ID \t\t\t=" << c.Appointment_Id << endl;
    cout << "The Patient ID\t=" << c.Patient_id << endl;
    cout << "The Appointment Time \t=" << c.Appoitment_Time << endl;
    cout << "The name of Parent Department\t\t=" << c.Parent_Dept << endl;
    cout << "The Appointment status (Checked/UnChecked)\t\t=" << c.Appointment_Status << endl;
    return Aout;
}
ofstream& operator << (ofstream& fout, Appointment& c) {

    fout << c.Department_Name << "\t";
    fout << c.Appointment_Id << "\t";
    fout << c.Patient_id << "\t";
    fout << c.Appoitment_Time << "\t";
    fout << c.Parent_Dept << "\t";
    fout << c.Appointment_Status << "\t" << endl;
    return fout;
}

//all funtions or operator overloded in Doctor class
Doctor::Doctor() {
    Total_No_Patients = 0;
    First_Name = Last_Name = Department_Name = Dental = Accident_Emergency = Orthopedics = Psychiatry = Physiotherapy = Email = Password = Gender = Qualification = Contact_no = Address = " ";
    Salary = 0;
}
istream& operator >> (istream& Din, Doctor& obj) {
    int dept_choice;
    string checkPassword;
    cout << "Enter the First Name of Doctor\t\t=";
    Din >> obj.First_Name;
    cout << "Enter the Last Name of Doctor\t\t=";
    Din >> obj.Last_Name;
    cout << "Enter the Department Name of Doctor\t\t=";
    cout << "Enter Department Name \t\t\t\n";
    cout << "Following are Departments in Our Hospital \n";
    cout << "1) Dental\n";
    cout << "2) Accident & Emergency\n";
    cout << "3) Orthopedics\n";
    cout << "4) Psychiatry\n";
    cout << "5) Physiotherapy\n";
    cout << "Your Department is = \n";
    Din >> obj.Department_Name;
    cout << "Enter the Doctor's ID\t\t=";
    Din >> obj.D_id;
    cout << "Enter the Email or Username of Doctor\t\t=";
    Din >> obj.Email;
    do {
        cout << "Enter the Password of Doctor\t\t=";
        Din >> obj.Password;
        cout << "Confirm the Password of Doctor\t\t=";
        Din >> checkPassword;
        if (obj.Password != checkPassword) {
            cout << "Password not Matched\n";
        }
    } while (obj.Password != checkPassword);
    cout << "Enter the Registeration Date\t\t=";
    Din >> obj.Reg_Date;
    cout << "Enter the Gender of Doctor\t\t=";
    Din >> obj.Gender;
    cout << "Enter the Blood Group of Doctor\t\t=";
    Din >> obj.Blood;
    cout << "Enter the Qualification of Doctor\t=";
    Din >> obj.Qualification;
    cout << "Enter the Contact_no of Doctor\t\t=";
    Din >> obj.Contact_no;
    cout << "Enter the Address of Doctor\t\t=";
    Din >> obj.Address;
    cout << "Enter the Salary of Doctor\t\t=";
    Din >> obj.Salary;
    return Din;
}
ifstream& operator >> (ifstream& fin, Doctor& obj) {
    fin >> obj.First_Name;
    fin >> obj.Last_Name;
    fin >> obj.Department_Name;
    fin >> obj.D_id;
    fin >> obj.Email;
    fin >> obj.Password;
    fin >> obj.Reg_Date;
    fin >> obj.Gender;
    fin >> obj.Blood;
    fin >> obj.Qualification;
    fin >> obj.Contact_no;
    fin >> obj.Address;
    fin >> obj.Salary;
    fin >> obj.Total_No_Patients;
    fin >> obj.Appointment_Id;
    fin >> obj.Appointment_Status;
    fin >> obj.Patient_id;

    return fin;
}
ostream& operator << (ostream& Dout, Doctor& obj) {
    Dout << setw(5) << " ";
    Dout << setw(20) << left << obj.First_Name << setw(20) << obj.Last_Name << setw(23) << obj.Gender << setw(18) << obj.Qualification << setw(17) << obj.Contact_no << obj.Email << endl;
    return Dout;
}
ofstream& operator << (ofstream& fout, Doctor& obj) {
    fout << obj.First_Name << "\t";
    fout << obj.Last_Name << "\t";
    fout << obj.Department_Name << "\t";
    fout << obj.D_id << "\t";
    fout << obj.Email << "\t";
    fout << obj.Password << "\t";
    fout << obj.Reg_Date << "\t";
    fout << obj.Gender << "\t";
    fout << obj.Blood << "\t";
    fout << obj.Qualification << "\t";
    fout << obj.Contact_no << "\t";
    fout << obj.Address << "\t";
    fout << obj.Salary << "\t";
    fout << obj.Total_No_Patients << "\n";
    fout << obj.Appointment_Id << "\t";
    fout << obj.Appointment_Status << "\t";
    fout << obj.Patient_id << "\t\n" << endl;
    return fout;
}
void Doctor::Doc_Appointments() {
    cout << "Appointment ID = " << this->Appointment_Id << endl;
    cout << "Appointment Time = " << this->Appoitment_Time << endl;
    cout << "Appointment Status (Checked / Unchecked) = " << this->Appointment_Status << endl;
    cout << "\n";
}
string Doctor::getTpassword() {
    return Password;
}
void Doctor::Appointments(Patient* S, int NoOfPat) //////Exception handling used....
{
    try {
        if (Total_No_Patients == 0) {
            throw Total_No_Patients;
        }
        this->pat = new Patient[this->Total_No_Patients];

    }
    catch (int Total_No_St) {
        cout << "Exception occured!!!!  Doctor has no Patient " << endl;
        return;
    }
    int j = 0;
    for (int i = 0; i < NoOfPat; i++) {
        if (this->Patient_id == S[i].patient) {
            pat[j] = S[i];
            j++;
        }
    }
    cout << setw(3) << " ";
    cout << setw(13) << left << "ID No" << setw(20) << "      Name        " << setw(15) << "Doctor" << "Usename\n";
    for (int i = 0; i < j; i++) {
        cout << i + 1 << ". " << pat[i] << endl;
    }
    int s, a;
    cout << "Enter ID No. of Patient\n";
    cin >> s;
    for (int i = 0; i < pat[s - 1].noOfAppoint; i++) {
        cout << pat[s - 1].A[i] << endl;
    }
    cout << "Enter Appointment name you want to update" << endl;
    cin >> a;
    cout << "Enter Total Appointments = ";
    cin >> pat[s - 1].A[a - 1].Appointment_Id;
    cout << "Appointment Status = ";
    cin >> pat[s - 1].A[a - 1].Appointment_Status;

}

//all funtions or operator overloded in Admin class
Admin::Admin() {
    ifstream fin;
    fin.open("Doctor.txt");
    if (!fin.is_open()) {
        cout << "File not Found\n";
    }
    fin >> noOfDoc;
    D = new Doctor[noOfDoc];
    for (int i = 0; i < noOfDoc; i++) {
        fin >> D[i];
    }
    fin.close();
    fin.open("Appointment.txt");
    if (!fin.is_open()) {
        cout << "File not Found\n";
    }
    fin >> noOfAppo;
    A = new Appointment[noOfAppo];
    for (int i = 0; i < noOfAppo; i++) {
        fin >> A[i];
    }
    fin.close();
    fin.open("Patient.txt");
    if (!fin.is_open()) {
        cout << "File not Found\n";
    }
    fin >> noOfPatient;
    P = new Patient[noOfPatient];
    for (int i = 0; i < noOfPatient; i++) {
        fin >> P[i];
    }
    fin.close();
    for (int i = 0; i < noOfDoc; i++) {
        for (int j = 0; j < noOfPatient; j++) {
            if (D[i].Patient_id == P[j].patient) {
                D[i].Total_No_Patients++;
            }
        }
    }
}
void Admin::adddoctor() {
    Doctor* N;
    noOfDoc++;
    N = new Doctor[noOfDoc];
    for (int i = 0; i < noOfDoc - 1; i++) {
        N[i] = D[i];
    }
    cin >> N[noOfDoc - 1];
    delete[] D;
    D = N;
}
void Admin::addPatient() {
    Patient* N;
    noOfPatient++;
    N = new Patient[noOfPatient];
    for (int i = 0; i < noOfPatient - 1; i++) {
        N[i] = P[i];
    }
    cin >> N[noOfPatient - 1];
    delete[] P;
    P = N;
}
void Admin::addAppointment() {
    noOfAppo++;
    Appointment* a = new Appointment[noOfAppo];
    for (int i = 0; i < noOfAppo - 1; i++) {
        a[i] = A[i];
    }
    cin >> a[noOfAppo - 1];
    delete[] A;
    A = a;
}
void Admin::AssignAppointment() {
    if (noOfDoc == 0 || noOfAppo == 0) {
        return;
    }
    int Select[2];
    viewAllDoctors();
    cout << "Select a Doctor to Assign a Appointment\t\t=";
    cin >> Select[0];
    viewAllAppointment();
    cout << "Select a Department to Assign\t\t\n";
    cout << "Following are Departments in Our Hospital \n";
    cout << "1) Dental\n";
    cout << "2) Accident & Emergency\n";
    cout << "3) Orthopedics\n";
    cout << "4) Psychiatry\n";
    cout << "5) Physiotherapy\n";
    cout << "Enter the Department you in which you want to take Appointment \n";

    cin >> Select[1];
    D[Select[0] - 1].Department_Name = A[Select[1] - 1].Department_Name;
    D[Select[0] - 1].Appointment_Id = A[Select[1] - 1].Appointment_Id;
    D[Select[0] - 1].Patient_id = A[Select[1] - 1].Patient_id;
    D[Select[0] - 1].Appoitment_Time = A[Select[1] - 1].Appoitment_Time;
    D[Select[0] - 1].Parent_Dept = A[Select[1] - 1].Parent_Dept;
    D[Select[0] - 1].Appointment_Status = A[Select[1] - 1].Appointment_Status;

}
void Admin::editPatient() {
    int select, select2;
    viewAllPatient();
    cout << "Select a Patient by its ID No.\t=";
    cin >> select;
    if ((select <= 0) && (select > noOfPatient)) {
        cout << "Invalid Input\n";
        return;
    }
    cout << "1) First Name\n";
    cout << "2) Last Name\n";
    cout << "3) Fee Status\n";
    cout << "4) Address\n";
    cout << "5) Contact number\n";
    cout << "Select a What do you want to change\t=";
    cin >> select2;
    switch (select2) {
    case 1:
        cout << "Enter the First Name of the Patient\t\t=";
        cin >> P[select - 1].First_Name;
        break;
    case 2:
        cout << "Enter the Last Name of the Patient\t\t=";
        cin >> P[select - 1].Last_Name;
        break;
    case 3:
        cout << "Enter Paid or UnPaid for the Fee of Patient\t\t=";
        cin >> P[select - 1].Fee_submitted;
        break;
    case 4:
        cout << "Enter the Address of the Patient\t\t=";
        cin >> P[select - 1].Address;
        break;
    case 5:
        cout << "Enter the Contact number of the Patient\t\t=";
        cin >> P[select - 1].Contact_No;
        break;
    default:
        cout << "Invalid Input\n";
        break;
    }
}
void Admin::editDoctor() {
    int select, select2;
    viewAllDoctors();
    cout << "Select a Doctor\t=";
    cin >> select;
    if ((select <= 0) && (select > noOfDoc)) {
        cout << "Invalid Input\n";
        return;
    }
    cout << "1) Address\n";
    cout << "2) Contact number\n";
    cout << "3) Qualification\n";
    cout << "4) Salary\n";
    cout << "Select a What do you want to change\t=";
    cin >> select2;
    switch (select2) {
    case 1:
        cout << "Enter the Address of the Doctor\t\t=";
        cin >> D[select - 1].Address;
        break;
    case 2:
        cout << "Enter the Contact Number of the Doctor\t\t=";
        cin >> D[select - 1].Contact_no;
        break;
    case 3:
        cout << "Enter the Qualification of the Doctor\t\t=";
        cin >> D[select - 1].Qualification;
        break;
    case 4:
        cout << "Enter the Salary of the Doctor\t\t=";
        cin >> D[select - 1].Salary;
        break;
    default:
        cout << "Invalid Input\n";
        break;
    }
}
void Admin::viewAllPatient() {
    cout << setw(3) << " ";
    cout << setw(13) << left << "ID No." << setw(20) << "      Name        " << setw(15) << "Department Name" << "Email\n";
    for (int i = 0; i < noOfPatient; i++) {
        cout << P[i] << endl;
    }
}
void Admin::viewAllDoctors() {
    cout << setw(3) << " ";
    cout << setw(20) << left << "First Name" << setw(20) << "Last Name" << setw(20) << " Gender" << setw(20) << "Qualification" << setw(20) << "Contact_no" << "Username\n";
    for (int i = 0; i < noOfDoc; i++) {
        cout << i + 1 << "." << D[i] << endl;
    }
}
void Admin::viewAllAppointment() {
    cout << setw(3) << " ";

    cout << setw(20) << left << "Appointment ID" << setw(20) << "Appointment status" << setw(20) << " Doctor Id" << setw(20) << "Dcotor Name" << setw(20) << "Parent Id" << setw(5) << "Parent Department\n";

    for (int i = 0; i < noOfAppo; i++) {
        cout << i + 1 << "." << A[i] << endl;
    }
}
void Admin::updateAppontment() {
    viewAllPatient();
    int s, a;
    cout << "Enter ID No. of Patient\n";
    cin >> s;
    for (int i = 0; i < P[s - 1].noOfAppoint; i++) {
        cout << P[s - 1].A[i] << endl;
    }
    cout << "Enter Appointment you want to update" << endl;
    cin >> a;
    cout << "Enter Appointment Status (Checked / Unchecked ) = ";
    cin >> P[s - 1].A[a - 1].Appointment_Status;

    cout << "Enter Appointment Time = ";
    cin >> P[s - 1].A[a - 1].Appoitment_Time;

}
void Admin::viewFeeStatus() {
    for (int i = 0; i < noOfPatient; i++) {
        cout << "Name = " << P[i].First_Name << " " << P[i].Last_Name << endl;
        cout << "ID = " << P[i].P_id << endl;
        cout << "Fee status (Paid / UnPaid) = " << P[i].Fee_submitted << endl;
        cout << "\n\n";
    }
}
//Extras
bool Admin::checkAppoforPatient(Appointment objC, Appointment* objS, int size) {
    for (int i = 0; i < size; i++) {
        if (objC.Appointment_Id == objS[i].Appointment_Id)
            return 0;
    }
    return 1;
}
bool Admin::CheckPatientByEmail(string Email, Patient& std) {
    for (int i = 0; i < noOfPatient; i++) {
        if (P[i].Email == Email) {
            std = P[i];
            return 1;
        }

    }

    cout << "Invalid Email..............." << endl;
    return 0;
}
bool Admin::checkDoctorByEmail(string Email, Doctor& Doc) {
    for (int i = 0; i < noOfDoc; i++) {
        if (D[i].Email == Email) {
            Doc = D[i];
            return 1;
        }

    }

    cout << "Invalid Email..............." << endl;
    return 0;
}
Patient* Admin::getPatientsForDoctor() {
    return P;
}
int Admin::getNoPatient() {
    return noOfPatient;
}
Admin::~Admin() {
    for (int i = 0; i < noOfAppo; i++) {
        for (int j = 0; j < noOfPatient; j++) {
            if ((A[i].Patient_id == P[j].patient) && (checkAppoforPatient(A[i], P[j].A, P[j].noOfAppoint))) {
                P[j].noOfAppoint++;
                Appointment* C1 = new Appointment[P[j].noOfAppoint];
                for (int k = 0; k < P[j].noOfAppoint - 1; k++) {
                    C1[k] = P[j].A[k];
                }
                P[j].A = C1;
                P[j].A[P[j].noOfAppoint - 1] = A[i];
            }
        }
    }
    for (int i = 0; i < noOfDoc; i++) {
        D[i].Total_No_Patients = 0;
        for (int j = 0; j < noOfPatient; j++) {
            if (D[i].Patient_id == P[j].patient) {
                D[i].Total_No_Patients++;
            }

        }

    }

    ofstream fout;
    fout.open("Doctor.txt");
    fout << noOfDoc << endl;
    for (int i = 0; i < noOfDoc; i++) {
        fout << D[i];
    }
    delete[] D;
    fout.close();
    fout.open("Appointment.txt");
    fout << noOfAppo << endl;
    for (int i = 0; i < noOfAppo; i++) {
        fout << A[i];
    }
    delete[] A;
    fout.close();
    fout.open("Patient.txt");
    fout << noOfPatient << endl;
    for (int i = 0; i < noOfPatient; i++) {
        fout << P[i];
    }
    delete[] P;
    fout.close();
}