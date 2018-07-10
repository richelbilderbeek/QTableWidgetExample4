#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <QApplication>
#include <memory>
#include "qtdialog.h"
#pragma GCC diagnostic pop

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  for (int i = 0; i != 4; ++i)
  {
    const int x = 50 + ((i % 4) * 400);
    const int y = 200;
    QVector<QString> text;
    if ((i %  4) >= 1) text.push_back("First and short item");
    if ((i %  4) >= 2) text.push_back("Second very long item that consists of text that is so long that it should trigger word wrapping of the text into multiple lines");
    if ((i %  4) >= 3) text.push_back("Third and short item");
    QtWidget * const d = new QtWidget(text); //Will be deleted at end of main
    d->setMinimumWidth(400);
    d->move(x, y);
    d->show();
  }
  return a.exec();
}

