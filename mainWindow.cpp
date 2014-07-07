#include <mainWindow.h>

JanelaPrincipal::JanelaPrincipal (QWidget* parent):QMainWindow(parent)
{
    //qDebug()<<"Entrando";
    for(int i=0;i<N_SORTERS;i++){
      vectors[i]=NULL;
      sortViews[i]=NULL;
      sorters[i]=NULL;
    }


    updateTimer.setInterval(150);

    QWidget *w = new QWidget();

    //QScrollArea *scrollArea=new QScrollArea();
    //scrollArea->setWidget(w);
    //scrollArea->setWidgetResizable(true);

    //this->setCentralWidget(scrollArea);
    this->setCentralWidget(w);

    QVBoxLayout *vbox = new QVBoxLayout();
    w->setLayout(vbox);

    //Number of items slider
    QHBoxLayout *hboxSliderItems = new QHBoxLayout();
    QLabel *labelSliderItemsPre = new QLabel("Number of items:");
    hboxSliderItems->addWidget(labelSliderItemsPre);
    sliderItems = new QSlider(Qt::Horizontal);
    sliderItems->setMinimum(1);
    sliderItems->setMaximum(500);
    sliderItems->setValue(15);
    hboxSliderItems->addWidget(sliderItems);
    QLabel *labelSliderItems = new QLabel(QString::number(sliderItems->value()));
    hboxSliderItems->addWidget(labelSliderItems);
    hboxSliderItems->addWidget(new QLabel("Items"));
    QObject::connect(sliderItems,SIGNAL(valueChanged(int)),labelSliderItems,SLOT(setNum(int)));
    QObject::connect(sliderItems,SIGNAL(valueChanged(int)),this,SLOT(setN(int)));
    QPushButton *pbShuffle = new QPushButton("Shuffle");
    QObject::connect(pbShuffle,SIGNAL(clicked()),this,SLOT(setupVectors()));
    hboxSliderItems->addWidget(pbShuffle);
    vbox->addLayout(hboxSliderItems);

    //Update time slider
    QHBoxLayout *hboxSlider = new QHBoxLayout();
    QLabel *labelSliderPre = new QLabel("Update time:");
    hboxSlider->addWidget(labelSliderPre);
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(1);
    slider->setMaximum(30);
    slider->setValue(15);
    hboxSlider->addWidget(slider);
    QLabel *labelSlider = new QLabel(QString::number(slider->value()));
    hboxSlider->addWidget(labelSlider);
    QObject::connect(slider,SIGNAL(valueChanged(int)),labelSlider,SLOT(setNum(int)));
    hboxSlider->addWidget(new QLabel("ms after each change"));
    vbox->addLayout(hboxSlider);


    QHBoxLayout *buttonsHbox = new QHBoxLayout();
    pb = new QPushButton("Start Sorting");
    buttonsHbox->addWidget(pb);
    pb2 = new QPushButton("Stop Sorting");
    buttonsHbox->addWidget(pb2);



    //Cria os ordenadores e os visualizadores
    QHBoxLayout *hbox = new QHBoxLayout();
    sorters[0] = new BubbleSorter();
    sorters[1] = new InsertionSorter();
    sorters[2] = new MergeSorter();
    sorters[3] = new QuickSorter();
    for(int i=0;i<N_SORTERS;i++){
        QVBoxLayout *vboxInt = new QVBoxLayout();
        sortViews[i] = new SortViewWidget();
        vboxInt->addWidget(sortViews[i]);
        QHBoxLayout* hbox2 = new QHBoxLayout();
        hbox2->addWidget(new QLabel("Total\nTime: "));
        timers[i] = new TimerWidget(this);
        hbox2->addWidget(timers[i]);
        lblTimes[i] = new QLabel();
        hbox2->addWidget(lblTimes[i]);
        lblTimes[i]->setAlignment(Qt::AlignCenter);
        vboxInt->addLayout(hbox2);
        hbox->addLayout(vboxInt);
        //QObject::connect(sorters[i],SIGNAL(vectorChanged(int)),sortViews[i],SLOT(updateElement(int)));
        QObject::connect(sorters[i],SIGNAL(finished()), timers[i] , SLOT(stopTimer()));
        QObject::connect(sorters[i],SIGNAL(finished()), sortViews[i], SLOT(redraw()));
        QObject::connect(&updateTimer, SIGNAL(timeout()), sortViews[i], SLOT(redraw()));
        QObject::connect(slider,SIGNAL(valueChanged(int)),sorters[i],SLOT(setInterval(int)));
        QObject::connect(sliderItems,SIGNAL(valueChanged(int)),sortViews[i],SLOT(redraw()));
        sortViews[i]->setVector(vectors[i]);
        sorters[i]->setInterval(slider->value());
    }

    sortViews[0]->setUpperText("Bubble Sort");
    sortViews[1]->setUpperText("Insertion Sort");
    sortViews[2]->setUpperText("Merge Sort");
    sortViews[3]->setUpperText("Quick Sort");

    vbox->addLayout(hbox);
    updateTimer.start();


    QObject::connect(pb,SIGNAL(clicked()), this , SLOT(startSorting()));
    QObject::connect(pb2,SIGNAL(clicked()), this , SLOT(stopSorting()));

    vbox->addLayout(buttonsHbox);

    setN(sliderItems->value());
    setVisible(true);

    setAttribute(Qt::WA_DeleteOnClose,true);
    QObject::connect(this,SIGNAL(destroyed()),QApplication::instance(),SLOT(quit()));

}

void JanelaPrincipal::startSorting(){
    for(int i=0;i<N_SORTERS;i++){
        if(sorters[i])
        timers[i]->startTimer();
        sorters[i]->sort(vectors[i]);
    }
    updateTimer.start();
}

void JanelaPrincipal::stopSorting(){
    updateTimer.stop();
    for(int i=0;i<N_SORTERS;i++){
        timers[i]->stopTimer();
        if(sorters[i])
            sorters[i]->requestInterruption();
            //sorters[i]->terminate();
            sorters[i]->wait();
            //sorters[i]->exit(0);
        }
}

JanelaPrincipal::~JanelaPrincipal(){
    for(int i=0;i<N_SORTERS;i++){
        sortViews[i]->setVector(NULL);
        sorters[i]->requestInterruption();
        //sorters[i]->terminate();
        sorters[i]->wait();
        if(sorters[i])
            sorters[i]->deleteLater();
        if(vectors[i])
            delete vectors[i];
    }
}

void JanelaPrincipal::setupVectors(){
    stopSorting();
    QVector<int> v = generateRandomVector();
    for(int i=0;i<N_SORTERS;i++){
        if(sortViews[i])
            sortViews[i]->setVector(NULL);
        if(vectors[i])
            delete vectors[i];
        vectors[i] = new QVector<int>(v);
        if(sortViews[i])
            sortViews[i]->setVector(vectors[i]);
    }

}

QVector<int> JanelaPrincipal::generateRandomVector(){
    qsrand(QDateTime::currentDateTime().currentMSecsSinceEpoch());
    QVector<int> ret(n);
    for(int i=0;i<n;i++){
       ret[i] =  qrand() % 200;
    }
    return ret;
}

void JanelaPrincipal::setN(int n){
    stopSorting();
    this->n = n;
    setupVectors();
}
