#include <iostream>
#include <curl/curl.h> // Include cURL library for HTTP requests

// Function to handle data from cURL
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://api.simsimi.com/request?text=hello&key=txeZQ~x6nfXp5c_Sa_UkG5eJWsJpgbmom5sCmXgl");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        else
            std::cout << readBuffer << std::endl;

        curl_easy_cleanup(curl);
    }

    QPushButton *emojiButton = new QPushButton("Emoji Stickers");
    layout->addWidget(emojiButton);

    QPushButton *galleryButton = new QPushButton("Image Gallery");
    layout->addWidget(galleryButton);

    QPushButton *walletButton = new QPushButton("Open Honey Wallet");
    layout->addWidget(walletButton);

    window.setLayout(layout);
    window.show();

    return app.exec();
}
    return 0;
}
