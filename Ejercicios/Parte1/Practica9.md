Realice las siguientes modificaciones en el menú de arranque de
Grub2:
• Establezca el tiempo de elección del menú a 60 segundos
• Haga que no se muestren la opción de recovery mode en el menú.
• Establezca la resolución inicial a 800x600
• Haga que suene un pitido al aparecer el menú.
• Haga que no aparezca memtest en el menú.

```bash
GRUB_DEFAULT=0
GRUB_TIMEOUT_STYLE=menu
GRUB_TIMEOUT=60
GRUB_DISTRIBUTOR=`( . /etc/os-release; echo ${NAME:-Ubuntu} ) 2>/dev/null || ech
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"
GRUB_CMDLINE_LINUX=""

#GRUB_GFXMODE=800x600

#GRUB_INIT_TUNE="480 440 1"


```
