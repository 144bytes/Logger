#include <logger/logger.hpp>

#include <thread>

/*
output: 2026-06-26 16:12:34.134335900; INFO; (1): Starting the app
output: 2026-06-26 16:12:34.134483700; DEBUG; (1): Running the threads
output: 2026-06-26 16:12:34.134863500; DEBUG; (2): Running a thread
...
output: 2026-06-26 16:12:34.135278800; INFO; (1): Finishing the app
*/

Logger GetLogger(const std::string& prefix = "")
{
    return Logger(prefix);
}

void f1()
{
    auto logger1 = GetLogger();

    // output: 2026-06-26 19:28:39.767827400; DEBUG; (2): Running a thread
    logger1(DEBUG) << "Running a thread";

    auto logger2 = GetLogger("f1"); // Each message has f1 prefix

    // output: 2026-06-26 19:28:39.767876200; INFO; f1(2): Running a thread but log to another logger
    logger2 << "Running a thread"
            << " but log to another logger"; // Default log level INFO
}

void f2()
{
    Logger logger{"f2"}; // Each message has f2 prefix

    // output: 2026-06-26 19:28:39.767833600; DEBUG; f2(3): Running a thread
    logger(DEBUG) << "Running a thread";

    const double timeSpent = 10.0;

    // output: 2026-06-26 19:28:39.767905700; WARNING; f2(3): Time spent in the thread: 10 seconds
    logger(WARNING) << "Time spent in the thread: "
                    << timeSpent
                    << " seconds";
}

void f3()
{
    auto logger = GetLogger("f3"); // Each message has f3 prefix

    // output: 2026-06-26 19:28:39.767831100; INFO; f3(4): Running a threa
    logger << "Running a thread"; // Default log level INFO

    const int i = 123;

    // output: 2026-06-26 19:28:39.767939500; ERROR; f3(4): My int is 123
    logger(ERROR) << "My int is " << i;

    // output: 2026-06-26 19:28:39.768056500; INFO; f3(4): This is a random message to test log levels
    logger << "This is a random message "
           << "to test log levels";
}

int main()
{
    auto logger = GetLogger();

    // output: 2026-06-26 19:28:39.767088600; INFO; (1): Starting the app
    logger << "Starting the app"; // Default log level INFO

    logger(DEBUG) << "Running the threads";

    std::thread t1(f1);
    std::thread t2(f2);
    std::thread t3(f3);

    t1.join();
    t2.join();
    t3.join();

    // output: 2026-06-26 19:28:39.768239700; INFO; (1): Finishing the app
    logger << "Finishing the app"; // Default log level INFO

    return 0;
}
