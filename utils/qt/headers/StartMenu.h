#ifndef START_MENU
#define START_MENU

#include <QWidget>
#include <QLabel>

class StartMenu: public QWidget{
    Q_OBJECT
  private:
    QLabel* option1;
    QLabel* option2;
    QLabel* option3;
  public:
    StartMenu(QWidget* parent = 0);
    void show();
};


#endif // !DEBUG
