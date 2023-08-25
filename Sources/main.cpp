#include "mainwindow.h"

void setRandomSeed()
{
    srand((unsigned)time(NULL));
}

int main(int argc, char* argv[])
{
    setRandomSeed();

    QApplication app(argc, argv);
    MainGame game;
    MainWindow window;

    window.setGame(&game);
    window.initialize();
    window.show();

    return app.exec();
}
