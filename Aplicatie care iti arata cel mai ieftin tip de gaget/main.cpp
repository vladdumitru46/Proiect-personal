#include "Tests.h"
#include "RepositoryGadgets.h"
#include "Service.h"
#include "GUI_Gadget.h"
#include <QtWidgets/QApplication>

int run_gui(int argc, char* argv[])
{
    QApplication a(argc, argv);
    RepositoryGadgets repo_gadget{ "Gadget_file.txt" };
    Service service_gadget{ repo_gadget };
    Gadget_type gadget_type{ service_gadget };
    GUI_Gadget gui{ service_gadget, gadget_type };
    gui.show();
    return a.exec();
}

int main(int argc, char *argv[])
{
    Tests tests;
    tests.run_tests();
    run_gui(argc, argv);
    return 0;
}
