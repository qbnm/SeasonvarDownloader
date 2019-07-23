#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QUrl>
#include <QWidget>
#include <QMovie>
#include <QStyle>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QClipboard>
#include <string>
#include <vector>
#include <download_screen.h>
#include <script_screen.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonGetAllTheLinks_clicked();
    void on_pushButtonCopyLinksToClipboard_clicked();
    void on_pushButtonDownloadFromLinks_clicked();
    void on_pushButtonGenerateScript_clicked();

private:
    std::vector<std::string> tokens; //For parsed urls
    Ui::MainWindow *ui;
    enum UrlType {fullUrl, justId, wrongAddress};
    void printNetError();
    void printIdError();
    MainWindow::UrlType checkUrl(std::string url);
    void replaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace);
    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data);
    int network_request(std::string* url, std::string* response);
    void parse_response(std::string* response, std::vector<std::string>* tokens);
    void print_tokens();
    void decode(std::string* token);
    void removeOrs(std::string* token);
    QMovie *loadingAnimation;
    void startLoadingAnimation();
    void stopLoadingAnimation();
    QNetworkAccessManager *manager;
    QNetworkRequest request;
};

#endif // MAINWINDOW_H
