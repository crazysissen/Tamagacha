#include "gameplay.hpp"

void gBuyMoney()
{
    std::string output =
        "\n"
        "Buy more money selected!\n"
        "Choose your desired package: \n"
        "[2 money (9.90 SEK)]  [5 money (19.90 SEK)]  #[10 money (29.90 SEK)]# [50 money (49.90 SEK)]%%%%%%\n"
        "10 money selected!%%%\n\n"
        "Please input your credit card information:\n"
        "Card number: %%%%%%&4263%% 9826%% 4026% 9299&%%%%   Visa card detected!\n"
        "Expiry date: %%%%%&02%%/%%2023&%%\n"
        "CVV: %%%%%&837&\n"
        ".%%%.%%%.%%%.%%%%%Valid.\n\n"
        "Confirm (y/n): %%%%%%%%y\n"
        ".%%%.%%%.%%Confirmed!%%\n\n"
        "Thank you for your purchase!\n\n"
        "You recieved #10 money#%%%%%%%%%%%\n\n\n";
        
    bool randomizing = false;
    bool colorizing = false;

    std::chrono::milliseconds duration(200);

    for (char c : output)
    {
        if (c == '#')
        {
            colorizing = !colorizing;

            if (colorizing)
            {
                std::cout << ct::Mod(ct::CYellow, ct::CBlack, ct::CSBold);
            }
            else
            {
                std::cout << ct::Mod(ct::CWhite, ct::CBlack, ct::CSReset);
            }
        }
        else if (c == '%')
        {
            std::this_thread::sleep_for(duration);
        }
        else if (c == '&')
        {
            randomizing = !randomizing;
        }
        else
        {
            if (randomizing)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(70 + rand() % 200));
            }

            std::cout << c;
            fflush(stdout);
        }
    }
}