// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
	struct Memento
	{
		int width;
		int color;

		Memento(int w, int c) : width(w), color(c){}
	};

	std::map<int, Memento*> memento_map;

public:
	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
	int save() {
		static int key = 0;
		++key;

		Memento* m = new Memento(penWidth, penColor);
		memento_map[key] = m;
		return key;
	}
	void restore(int restore_key) {
		auto backup = memento_map.find(restore_key);
		if (backup == memento_map.end())
			return;
		penWidth = backup->second->width;
		penColor = backup->second->color;
		delete backup->second;
		memento_map.erase(restore_key);
	}
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.save();

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	g.restore(token);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
}









