#include "mantebutton.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
ManteButton::ManteButton()
{

}

void ManteButton::mousePressEvent(QMouseEvent *event)
{
    if (this->text().compare("buscar")==0){
        int ndato=this->mant->linelist->at(0)->text().toInt();
        QString dato=this->mant->string.split(";").at(ndato);
        for (int i=0;i<dato.split(",").length();i++){
            this->mant->labellist->at(i)->setText(dato.split(",").at(i));
        }
    }
    else if (this->text().compare("agregar")==0){
        qDebug()<<"entro a agregar";
        fstream fin, fout;

        // Open the existing file
        fin.open("movie_metadata.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("movie_metadatanew.csv", ios::out);

        int  count = 0, i;
        string line, word;
        vector<string> row;

        // Get the roll number
        // to decide the data to be deleted

        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (!fin.eof()) {

            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            int row_size = row.size();


            // writing all records,
            // except the record to be deleted,
            // into the new file 'reportcardnew.csv'
            // using fout pointer

                if (!fin.eof()) {
                    for (i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ",";
                    }
                    fout << row[row_size - 1] << "\n";
                }




            if (fin.eof()){
                for (i = 0; i <this->mant->string.split(";").at(0).split(",").length()-1; i++) {
                    QString str=this->mant->linelist->at(i+1)->text();
                    fout << str.toStdString() << ",";
                }
                QString str=this->mant->linelist->at(mant->string.split(";").at(0).split(",").length())->text();
                fout << str.toStdString() << "\n";
                count = 1;
                break;
            }
        }
        if (count == 1)
            cout << "Record created\n";
        else
            cout << "Record not found\n";

        // Close the pointers
        fin.close();
        fout.close();
        remove("movie_metadata.csv");
        rename("movie_metadatanew.csv", "movie_metadata.csv");
    }
    else if (this->text().compare("editar")==0){
        qDebug()<<"entro a editar";
        fstream fin, fout;

        // Open the existing file
        fin.open("movie_metadata.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("movie_metadatanew.csv", ios::out);

        int rollnum, roll1, count = 0, i;

        string line, word;
        vector<string> row;

        // Get the roll number
        // to decide the data to be deleted
        rollnum=this->mant->linelist->at(0)->text().toInt()-1;;

        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        roll1 = 0;
        while (!fin.eof()) {

            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            int row_size = row.size();


            // writing all records,
            // except the record to be deleted,
            // into the new file 'reportcardnew.csv'
            // using fout pointer
            if (roll1 != rollnum) {
                if (!fin.eof()) {
                    for (i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ",";
                    }
                    fout << row[row_size - 1] << "\n";
                }

            }
            else {
                count = 1;
                for (i = 0; i < row_size - 1; i++) {
                    QString str=this->mant->linelist->at(i+1)->text();
                    if (str.compare("")==0){fout << row[i] << ",";}else{
                        fout << str.toStdString() << ",";
                    }

                }
                QString str=this->mant->linelist->at(row_size)->text();
                if (str.compare("")==0){fout << row[row_size - 1] << "\n";}else{
                fout << str.toStdString() << "\n";}
            }
            roll1++;
            if (fin.eof())
                break;
        }
        if (count == 1)
            cout << "Record edited\n";
        else
            cout << "Record not found\n";

        // Close the pointers
        fin.close();
        fout.close();
        remove("movie_metadata.csv");
        rename("movie_metadatanew.csv", "movie_metadata.csv");
    }
    else if (this->text().compare("eliminar")==0){
            qDebug()<<"entro a elminar";
            fstream fin, fout;

            // Open the existing file
            fin.open("movie_metadata.csv", ios::in);

            // Create a new file to store the non-deleted data
            fout.open("movie_metadatanew.csv", ios::out);

            int rollnum, roll1, count = 0, i;
            string line, word;
            vector<string> row;

            // Get the roll number
            // to decide the data to be deleted
            rollnum=this->mant->linelist->at(0)->text().toInt()-1;;

            // Check if this record exists
            // If exists, leave it and
            // add all other data to the new file
            roll1 = 0;
            while (!fin.eof()) {

                row.clear();
                getline(fin, line);
                stringstream s(line);

                while (getline(s, word, ',')) {
                    row.push_back(word);
                }

                int row_size = row.size();


                // writing all records,
                // except the record to be deleted,
                // into the new file 'reportcardnew.csv'
                // using fout pointer
                if (roll1 != rollnum) {
                    if (!fin.eof()) {
                        for (i = 0; i < row_size - 1; i++) {
                            fout << row[i] << ",";
                        }
                        fout << row[row_size - 1] << "\n";
                    }

                }
                else {
                    count = 1;
                }
                roll1++;
                if (fin.eof())
                    break;
            }
            if (count == 1)
                cout << "Record deleted\n";
            else
                cout << "Record not found\n";

            // Close the pointers
            fin.close();
            fout.close();
            remove("movie_metadata.csv");
            rename("movie_metadatanew.csv", "movie_metadata.csv");
    }
    else if (this->text().compare("actualizar")==0){
        string string="";
        ifstream lectura;
        lectura.open("movie_metadata.csv",ios::in);

        for (std::string linea; std::getline(lectura, linea); )
        {
            stringstream registro(linea);
            string.append(linea);
            string.append(";");

        }
        this->mant->string=string.c_str();
        this->mant->cargar_dataset();
    }
}
