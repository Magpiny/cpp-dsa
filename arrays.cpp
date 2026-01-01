// implementing arrays
//
#include <optional>
#include <print>
#include <stdexcept>
#include <string>

class GameEntry {
private:
  std::string name;
  int score;

public:
  GameEntry(const std::string &&n = "", int s = 0);
  std::string get_name() const;
  int get_score() const;
  virtual ~GameEntry() noexcept = default;
};

class Scores {
private:
  int max_entries;
  int num_entries;
  GameEntry *entries;

public:
  Scores(int maxEntries = 10);
  ~Scores();
  void add(const GameEntry &e) const;
  std::optional<GameEntry> remove(int i);
};

int main(int argc, char *argv[]) { return 0; }

GameEntry::GameEntry(const std::string &&n, int s)
    : name(std::move(n)), score(s) {};

std::string GameEntry::get_name() const { return name; };

int GameEntry::get_score() const { return score; };
