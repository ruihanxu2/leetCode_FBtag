// 比较特别的地方就是如何goback和方向的选择
class Solution {
	vector<vector<int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	set<pair<int, int> > visited;
	
	void goBack(Robot& robot){
		robot.turnLeft();
		robot.turnLeft();
		robot.move();
		robot.turnLeft();
		robot.turnLeft();
	}
	
	void dfs(Robot& robot, int curDir, int r, int c){
		visited.insert({r, c});
		robot.clean();
		for(int i = 0; i < 4; i++){
			int newDir = (curDir + i) % 4;
			int newRow = r + dir[newDir][0];
			int newCol = c + dir[newDir][1];
			if(!visited.count({newRow, newCol}) && robot.move()){
				dfs(robot, newDir, newRow, newCol);
				goBack(robot);
			}
			robot.turnRight(); // dir++
			
		}
	}
public:
	void cleanRoom(Robot& robot) {
		dfs(robot, 0, 0, 0);
	}
};

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */