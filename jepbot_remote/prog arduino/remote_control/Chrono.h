class Chrono:
{

public:
  Chrono();
  void start();
  void resume();
  int getTime();

private:
  int start_time;
}

