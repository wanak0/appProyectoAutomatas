#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEditor->clear();
    ui->tableDisplay->clearContents();
    ui->labelFileName->setText("");
}


void MainWindow::on_actionSave_triggered()
{
    //QFile f=ui->labelFileName->text();

    if(ui->labelFileName->text()==""){
        on_actionSave_As_triggered();
    }else{
        QFile f=ui->labelFileName->text();
        //lo abrimos con el IODevice WriteOnly, para solamente escribir en el
        f.open(QIODevice::WriteOnly);
        //con el QTextStream se hace el manejo del texto, sirve de Buffer, se le pasa como parametro
        //la direccion del archivo en donde queremos guardar nuestro Texto
        QTextStream stream(&f);
        //Gracias a la sobrecarga de operadores simplemente se le concatena al stream
        stream<<ui->textEditor->toPlainText();
        //con el flush sse obliga al buffer a escribir todo lo que tenga en el mismo
        stream.flush();
        //por ultimo cerramos el archivo para evitar potenciales fugas de memoria
        f.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    //instanciamos un objeto QFile, que en si es para poder acceder y crear archivos desde el IDE
    //QFile f=QFileDialog::getSaveFileName(this,tr("Save file"),QDir::currentPath(),tr(".txt(*.txt)"));
    QString name=QFileDialog::getSaveFileName(this,"Save as...","/Users/user/Documents",tr(".txt(*.txt)"));
    ui->labelFileName->setText(name);
    QFile f(name);
    //lo abrimos con el IODevice WriteOnly, para solamente escribir en el
    f.open(QIODevice::WriteOnly);
    //con el QTextStream se hace el manejo del texto, sirve de Buffer, se le pasa como parametro
    //la direccion del archivo en donde queremos guardar nuestro Texto
    QTextStream stream(&f);
    //Gracias a la sobrecarga de operadores simplemente se le concatena al stream
    stream<<ui->textEditor->toPlainText();
    //con el flush sse obliga al buffer a escribir todo lo que tenga en el mismo
    stream.flush();
    //por ultimo cerramos el archivo para evitar potenciales fugas de memoria
    f.close();
}


void MainWindow::on_actionOpen_triggered()
{
    on_actionNew_triggered();
         // *METODO PARA ABRIR ARCHIVOS DE TEXTO PLANO*
    //primero obtenemos el nombre del archivo, junto con la ruta debido a que
    //el metodo getOpenfileName() nos regresa un QString con: path+name
                                                    // sustituir ruta en caso de ser necesario
    QString fich=QFileDialog::getOpenFileName(this,"","/Users/user/Documents");
    //usando ifstream le pasamos ese nombre, sin olvidar de pasar el QString
    //a std::string, debido a que este es el tipo parametro que acepta el constructor
    ifstream file(fich.toStdString());
    //se usan dos variables strings, la primera para leer los datos en la linea, la segunda
    //para guardar las lineaS(plural) para tenerlo en todo
    string data,lines;
    //se muestra al usuario todo (la ruta y el nombre)
    ui->labelFileName->setText(fich);
    //si el el ifstream tiene algun error, se informa al usuario que el archivo no existe
    if(file.fail())
        QMessageBox::about(this,"ERROR","FILE DOESN'T EXISTS");
    //ciclo para leer el archivo y formatearlo
    while(!file.eof()){
        getline(file,data);
        lines.append(data);
        lines.append("\n");
    }
    //se muestra el contenido del archivo el text editor
    ui->textEditor->insertPlainText(QString::fromStdString(lines));
}


void MainWindow::on_actionClose_triggered()
{
    this->close();
}


void MainWindow::on_actionAnalize_triggered()
{
    sintac.lex->setCad(ui->textEditor->toPlainText().toStdString());
    sintac.lex->scanner();
    sintac.analizar();
    for(staInProd e:sintac.si){
        ui->tableDisplay->insertRow(ui->tableDisplay->rowCount());
        ui->tableDisplay->setItem(ui->tableDisplay->rowCount()-1,0,new QTableWidgetItem(QString::fromStdString(e.stack)));
        ui->tableDisplay->setItem(ui->tableDisplay->rowCount()-1,1,new QTableWidgetItem(QString::fromStdString(e.input)));
        ui->tableDisplay->setItem(ui->tableDisplay->rowCount()-1,2,new QTableWidgetItem(QString::fromStdString(e.prod)));
    }
}

