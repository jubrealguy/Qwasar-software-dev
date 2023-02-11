function my_spaceship(move) {
    var x= 0;
    var y= 0;
    var directions = 'up';
    
    for (var i = 0; i < move.length; i++) {
        if (directions === 'up') {
            if (move[i] === 'A') {
                y -= 1;
            }
            else if (move[i] === 'R') {
                directions = 'right';
            }
            else if (move[i] === 'L') {
                directions = 'left';
            }
        }

        else if (directions === 'right') {
            if (move[i] === 'A') {
                x += 1;
            }
            else if (move[i] === 'R') {
                directions = 'down';
            }
            else if (move[i] === 'L') {
                directions = 'up';
            }
        }

        else if (directions === 'left') {
            if (move[i] === 'A') {
                x -= 1;
            }
            else if (move[i] === 'R') {
                directions = 'up';
            }
            else if (move[i] === 'L') {
                directions = 'down';
            }
        }

        else if (directions === 'down') {
            if (move[i] === 'A') {
                y += 1;
            }
            else if (move[i] === 'R') {
                directions = 'left';
            }
            else if (move[i] === 'L') {
                directions = 'right';
            }
        }
    }

    var position = {
        x: x,
        y: y,
        directions: directions
    };

    return `{x: ${position.x}, y: ${position.y}, direction: '${position.directions}'}`;
}