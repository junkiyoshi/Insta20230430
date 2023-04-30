#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetLineWidth(2);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	int hue = ofRandom(255);
	float radius = 35;
	float len = 10;
	bool flag = true;

	for (int x = -300; x <= 300; x += 100) {

		for (int y = -300; y <= 300; y += 100) {

			ofPushMatrix();
			ofTranslate(x, y);

			flag = !flag;

			for (int i = 0; i < 4; i++) {

				vector<glm::vec2> vertices_1, vertices_2;
				float deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 10) * (flag ? 1 : -1);

				for (float deg = deg_start; deg < deg_start + 90; deg += 1) {

					vertices_1.push_back(glm::vec2((radius - len * 0.5) * cos(deg * DEG_TO_RAD), (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
					vertices_2.push_back(glm::vec2((radius + len * 0.5) * cos(deg * DEG_TO_RAD), (radius + len * 0.5) * sin(deg * DEG_TO_RAD)));
				}

				reverse(vertices_2.begin(), vertices_2.end());

				color.setHsb(hue, 255, 155);

				ofFill();
				ofSetColor(color);

				ofBeginShape();
				ofVertices(vertices_1);
				ofVertices(vertices_2);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(255);

				ofBeginShape();
				ofVertices(vertices_1);
				ofVertices(vertices_2);
				ofEndShape(true);

				hue = (hue + (int)ofRandom(20, 120)) % 255;
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}