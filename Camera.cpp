//
//  Camera.cpp
//  Lab5
//
//  Created by CGIS on 28/10/2016.
//  Copyright © 2016 CGIS. All rights reserved.
//

#include "Camera.hpp"

namespace gps {
    
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget)
    {
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraDirection = glm::normalize(cameraTarget - cameraPosition);
        this->cameraRightDirection = glm::normalize(glm::cross(this->cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
		this->cameraUp = glm::normalize(glm::cross(cameraRightDirection, cameraDirection));

	}
    
    glm::mat4 Camera::getViewMatrix()
    {
        return glm::lookAt(cameraPosition, cameraPosition + cameraDirection , glm::vec3(0.0f, 1.0f, 0.0f));
    }

	glm::vec3 Camera::getCameraTarget()
	{
		return cameraTarget;
	}
    
    void Camera::move(MOVE_DIRECTION direction, float speed)
    {
        switch (direction) {
            case MOVE_FORWARD:
                cameraPosition += cameraDirection * speed;
                break;
                
            case MOVE_BACKWARD:
                cameraPosition -= cameraDirection * speed;
                break;
                
            case MOVE_RIGHT:
                cameraPosition += cameraRightDirection * speed;
                break;
                
            case MOVE_LEFT:
                cameraPosition -= cameraRightDirection * speed;
                break;
        }
    }
    
    void Camera::rotate(float pitch, float yaw)
    {
		cameraDirection = glm::vec3(cos(yaw) * sin(pitch), sin(yaw), cos(yaw) * cos(pitch));
		cameraRightDirection = glm::vec3(sin(pitch - 3.14f / 2.0f), 0, cos(pitch - 3.14f / 2.0f));
		cameraUp = glm::normalize(glm::cross(cameraRightDirection, cameraDirection));
    }
    
}
