#ifndef __WIDGETS_READY_H__
#define __WIDGETS_READY_H__

#include <QWidget>

#include "../Models/flappybird.h"
#include "../Widgets/resource.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class ReadyWidget;
}

QT_END_NAMESPACE

class ReadyWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::ReadyWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        ReadyWidget(QWidget* parent = nullptr);
        ~ReadyWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
};
#endif