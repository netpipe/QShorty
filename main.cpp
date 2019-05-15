#include "qxtglobalshortcut/qxtglobalshortcut.h"

#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QProcess>
#include <QDebug>

#include "main.moc"

int mevent(QString eventname){

    if (eventname == ""){

    };


}
// for getting more detailed window information later. for adding windows via gui
/*//https://stackoverflow.com/questions/1201179/how-to-identify-top-level-x11-windows-using-xlib
void CSoftwareInfoLinux::enumerateXWindows(Display *display, Window rootWindow)
{

    Window parent;
    Window *children;
    Window *child;
    quint32 nNumChildren;

    XTextProperty wmName;
    XTextProperty wmCommand;

    int status = XGetWMName(display, rootWindow, &wmName);
    if (status && wmName.value && wmName.nitems)
    {
        int i;
        char **list;
        status = XmbTextPropertyToTextList(display, &wmName, &list, &i);
        if (status >= Success && i && *list)
        {
            qDebug() << "Found window with name:" << (char*) *list;
        }

        status = XGetCommand(display, rootWindow, &list, &i);
        if (status >= Success && i && *list)
        {
            qDebug() << "... and Command:" << i << (char*) *list;
        }

        Window tf;
        status = XGetTransientForHint(display, rootWindow, &tf);
        if (status >= Success && tf)
        {
            qDebug() << "TF set!";
        }

        XWMHints *pHints = XGetWMHints(display, rootWindow);
        if (pHints)
        {
            qDebug() << "Flags:" << pHints->flags
                    << "Window group:" << pHints->window_group;
        }
    }

    status = XQueryTree(display, rootWindow, &rootWindow, &parent, &children, &nNumChildren);
    if (status == 0)
    {
        // Could not query window tree further, aborting
        return;
    }

    if (nNumChildren == 0)
    {
        // No more children found. Aborting
        return;
    }

    for (int i = 0; i < nNumChildren; i++)
    {
        enumerateWindows(display, children[i]);
    }

    XFree((char*) children);
}
*/


int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    QMainWindow mainWindow;
  //  MyGlobalShortcutHandler myGlobalShortcut();

//     QApplication app(argc, argv);
//     QPixmap oPixmap(32,32);
     //QMenu* menu1 = new QMenu(); // want to get a context menu from system tray
   //  oPixmap.load ("systemTrayIcon.png");

     //QIcon oIcon( oPixmap );

   //  QSystemTrayIcon *trayIcon = new QSystemTrayIcon(oIcon);
  //   qDebug() << trayIcon->isSystemTrayAvailable();
   //  trayIcon->setContextMenu( menu1);
 //    trayIcon->setVisible(true);
  //   trayIcon->showMessage("Test Message", "Text", QSystemTrayIcon::Information, 1000);



     const QKeySequence shortcut("Ctrl+Shift+T");
     const QKeySequence sgithub("Ctrl+G");
     const QxtGlobalShortcut globalShortcut(shortcut);
     const QxtGlobalShortcut github(sgithub);

     QObject::connect(
                 &globalShortcut, &QxtGlobalShortcut::activated, &globalShortcut,
                 [&]{
                          qDebug() << "Global shortcut tester";
                     QApplication::quit();
                 });

     QObject::connect(
                 &github, &QxtGlobalShortcut::activated, &github,
                 [&]{
                          qDebug() << "Global shortcut tester";


                    //      QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
                     //     QCoreApplication::postEvent (receiver, event);

                           QString test="xdotool key ";
                                   test.append('"');
                                   test.append("Shift+Insert");
                                   test.append( '"');
                                  //qDebug() << test;
QStringList arguments;
arguments << "./paste.sh";
//result=$(wmctrl -l | grep 'TODO - gvim' | grep -Eo '0x[0-9a-f]+')
//arguments << "window=$(xdotool getactivewindow);xdotool windowactivate $window key Shift+Insert;";
                          QProcess::execute( "/bin/sh", arguments );
                 });


     //https://github.com/ebranlard/xdotool-for-windows


//https://unix.stackexchange.com/questions/87831/how-to-send-keystrokes-f5-from-terminal-to-a-gui-program
  //   xdotool windowactivate $(xdotool search --class Chrome) &&
  //   xdotool key F5 &&
  //   xdotool windowactivate $(xdotool getactivewindow)

     //xdotool key --window "$(xdotool search --class Chromium | head -1)" Ctrl+Tab


     /*
     //https://www.qtcentre.org/threads/62572-send-key-even-to-other-aplication
     //#include "windows.h"

     HWND mywindow; uint keyCode;
     QString str;

        str = 'notepad';
        wchar_t* name = new wchar_t[str.length() + 1];
        str.toWCharArray(name);
        mywindow = FindWindow(name,0);
        SetForegroundWindow(mywindow);
        keyCode = VK_F1; // F1 key
        //uint keyCode = PP_DATA.key;
        PostMessage(mywindow, WM_KEYDOWN, keyCode, 0); // key down
        PostMessage(mywindow, WM_KEYUP, keyCode, 0); // key up
*/


    mainWindow.show();
    return application.exec();
}
