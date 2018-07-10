#ifndef QTWIDGET_H
#define QTWIDGET_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include <QTableWidget>
#pragma GCC diagnostic pop

class QtWidget : public QTableWidget
{
  Q_OBJECT

public:
  explicit QtWidget(
    const QVector<QString>& text = {},
    QWidget *parent = 0
  );
  QtWidget(const QtWidget&) = delete;
  QtWidget& operator=(const QtWidget&) = delete;
  ~QtWidget() noexcept;
private:
};

#endif // QTWIDGET_H
