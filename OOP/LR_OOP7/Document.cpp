//
//  document.cpp
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include "Document.h"


void Document::addFigure(std::unique_ptr<figure> fig) {
	figures.emplace_back(std::move(fig));
	
	commandStack.push(std::make_unique<CommandAdd>(figures.size() - 1, this));

}
void Document::removeFigure(int id) {
	commandStack.push(std::make_unique<CommandRemove>(id, figures[id], this));
	figures.erase(figures.begin() + id);

}
void Document::undo() {
	if (commandStack.size()) {

		commandStack.top() -> undo();

		commandStack.pop();
	
	}
}


void Document::render(const sdl::renderer& renderer) {
	for (const std::shared_ptr<figure>& figure : figures) {
		figure -> render(renderer);
	}
}

void Document::Save(std::ofstream& os) {
	for (const std::shared_ptr<figure>& figure : figures) {
		figure -> save(os);
	}
}

void Document::Load(std::ifstream& is) {

	figures.clear();

	while ( ! commandStack.empty() )
	{
    	commandStack.pop();
	}
	
	std::string type;

	while(std::getline(is, type)) {
		 if (type == "triangle") {
			std::array<vertex, 3> vrt;
			for (int i = 0; i < 3; i++) {
				is >> vrt[i];
			}
			std::vector<int> colorTmp(3);
			for (int i = 0; i < 3; i++) {
				is >> colorTmp[i];
			}
			std::unique_ptr<figure> trap = std::make_unique<triangle>(vrt);
			trap->setColor(colorTmp);
			figures.emplace_back(std::move(trap));
		}
		else if (type == "hexagon") {
			std::array<vertex, 6> vrt;
			for (int i = 0; i < 6; i++) {
				is >> vrt[i];
			}
			std::vector<int> colorTmp(3);
			for (int i = 0; i < 3; i++) {
				is >> colorTmp[i];
			}
			std::unique_ptr<figure> trap = std::make_unique<hexagon>(vrt);
			trap->setColor(colorTmp);
			figures.emplace_back(std::move(trap));
		}
		else if (type == "octagon") {
			std::array<vertex, 8> vrt;
			for (int i = 0; i < 8; i++) {
				is >> vrt[i];
			}
			std::vector<int> colorTmp(3);
			for (int i = 0; i < 3; i++) {
				is >> colorTmp[i];
			}
			std::unique_ptr<figure> trap = std::make_unique<octagon>(vrt);
			trap->setColor(colorTmp);
			figures.emplace_back(std::move(trap));
		}
			
	}

}

void Document::clear() {

	while ( ! commandStack.empty() )
	{
    	commandStack.pop();
	}

	figures.clear();

}