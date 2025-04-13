#!/bin/bash

# Color
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
RESET='\033[0m'

# 1. Revoke X11 access (if you opened it for the container)
echo -e "${CYAN}Revoking X11 access...${RESET}"
xhost - 127.0.0.1

# 2. Stop and remove Docker containers, networks, and volumes
echo -e "${YELLOW}Stopping and cleaning up Docker containers, networks, and volumes...${RESET}"
docker-compose down --volumes

# 3. Clean up unused Docker images, containers, networks, and volumes
echo -e "${YELLOW}Cleaning up unused Docker images, containers, networks, and volumes...${RESET}"
docker system prune -af --volumes


# Final message
echo -e "${GREEN}Cleanup completed successfully!${RESET}"