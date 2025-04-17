# Hello 42 Visitor 👋

If you’ve stumbled upon this repo, you're probably curious how someone else built their `cub3d` project.  

This work was done by my amazing teammate ✨[Val](https://github.com/vdeva)✨ and me C:

I done the parsing for map and Val done the math for ray casting.

---

## 🚀 Most Helpful Thing for you

This repo includes a `Dockerfile` and a `docker-compose.yml` — and that’s the part that might really help you.

At the 42 workstations, you usually have the already installed `minilibx`.  
But if you're working on your **own computer** (especially on **macOS**), setting that up can be a pain.

This setup will:
- Spin up a Linux container with everything pre-installed
- Give you the similar dev environment as 42's computers (change the image to ubuntu if you prefer)
- Let you run GUI apps from inside the container, and check your `cub3d` with your mac

---

## 💻 Requirements (on your host machine)

Before you begin, make sure you have:

- ✅ [Docker](https://www.docker.com/products/docker-desktop/)
- ✅ [XQuartz](https://www.xquartz.org/) (for GUI display on macOS)

---

## 🛠️ Getting Started

Run the dev environment with:

```bash
./start_dev.sh
```

This script will:

- Build the Docker container
- Start it using docker-compose
- Automatically enter the container shell at /home/program

Now you're ready to make and run your project from inside the container. 🎮

---

## 🖼️ GUI Setup

To get graphical output, follow these steps:

1. Start XQuartz:
```terminal
open -a XQuartz
```

2. Enable network connections (first time only)
In XQuartz → Preferences → Security → ✅ Allow connections from network clients
Then restart XQuartz.

3. Test the connection 
Inside your container: 
```sh 
xeyes
```
If xeyes opens a window — you're golden 🌟

## 📁 Project Structure
This repo uses a bind mount (./program:/home/program), which means:

Any code you edit in your ./program folder on your host is immediately reflected inside the container.

You get to use VS Code on your Mac, while compiling and running inside Linux. Best of both worlds.

## 👾 Basic Docker Commands
- Start docker compose at the first time (-d flag for docker to run in the background/detached mode):
```bash
docker-compose up -d
```

- Stop docker compose (without removing the conatiners and network):
```bash
docker-compose stop
```

- Back to work with docker:
```bash
docker-compose start
```

- Done for good and remove containers and networks:
```bash
docker-compose down
```

- Full clean up for all unused image, container, volumes (-a removes all unused images, -f force and skip confirmation prompt, --volumes delete all unused volumes):
```bash
docker system prune -af --volumes
```
p.s. always be careful with the -f flag... don't use it when you're not sure you want to wipe out everything

- Check running containers (-a for all when checking both running and stopped ones):
```bash
docker ps
```

- Enter a running container:
```bash
docker exec -it <container_name_or_id> /bin/bash
```
p.s. If the container doesn't have bash (e.g. Alpine), do `sh` instead

## 🧹 Clean Up

When you’re done working on this project:
```bash
./cleanup.sh
```

This will:

- Revoke X11 permissions (xhost -)
- Stop and remove the Docker container and network

⚠️ Note: You don’t need to run this every time — only when you're truly done.
Otherwise, you’ll have to rebuild the container again next time. It's gonna take time ... be patient C:

## 🧠 Final Notes

Enjoy working in the container without the pain of installing library/package and path issues on different machines! 🤯
