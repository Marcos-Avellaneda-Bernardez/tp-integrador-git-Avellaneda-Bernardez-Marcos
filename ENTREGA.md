#   Entrega del Trabajo Práctico Integrador

##  Datos del participante
* Nombre:
    - Marcos Avellaneda Bernardez
* Curso:
    - Introducción a Git y GitHub para la Gestión de Proyectos Digitales
* Fecha de entrega:
    - COMPLETAR

## Enlaces
* Repositorio de GitHub:
    - https://github.com/Marcos-Avellaneda-Bernardez/tp-integrador-git-Avellaneda-Bernardez-Marcos.git
* Issue:
    - https://github.com/Marcos-Avellaneda-Bernardez/tp-integrador-git-Avellaneda-Bernardez-Marcos/issues/1

## Comandos principales utilizados
1) Creamos la carpeta del proyecto y nos movemos a la carpeta
    - mkdir tp-integrador-git-Avellaneda-Bernardez-Marcos
    - cd tp-integrador-git-Avellaneda-Bernardez-Marcos/
En esta carpeta trabajaremos en el proyecto

2) Agregamos el nombre de usuario y un email
    - git config --global user.name "Marcos Avellaneda Bernardez"
    - git config --global user.email "marcosavellaneda13@gmail.com"

3) Creamos el repositorio local
    - git init
4) Para consultar el estado del repositorio
    - git status
5) Para enviar los archivos al area intermedia, _staging area_
    - git add [ lista de archivos/directorios ] o git add . para agregar todo
        - En mi caso tengo: 
            - .gitignore (para ignoran archivos temporeles, por ejempl los usados por algun editor)
            - Proyecto/ (la carpeta del proyecto) con archivos
                + Config.cpp
                + Config.h
                + Proyecto.ino
            - README.md (para explicar lo que hay en el repositorio)
            - ENTREGA.md (necesario para la eveluacion del trabajo integrador)

6) Primer Commit
    - git commit -m "Primer borrador"

7) Yo le cambie el nombre a la rama principal _master_ a *main* con
    - git branch -M main

8) Para consultar el historial de commits
    - git log --oneline
        + hasta el momento: 
            * 87ca4c0 (HEAD -> main) Primer borrador
    - o git log para un informe mas detallado

9) Creamos un repositorio remoto en github.com

10) Enlazamos el repositorio local con el remoto
    - git@github.com:Marcos-Avellaneda-Bernardez/tp-integrador-git-Avellaneda-Bernardez-Marcos.git

11) Hacemos un primer push
    - git push -u origin main
    
12) De ahora en adelante usamos 
    + git push:  para enviar los cambios del repositorio local al remoto
    + git pull para traer los cambios del repositorio remoto al local

13) En caso de querer ver/trabajar en el repositorio desde otro lugar, lo clonamos con:
    - git clone "https://github.com/Marcos-Avellaneda-Bernardez/tp-integrador-git-Avellaneda-Bernardez-Marcos.git"

14) De ahora en adelante la secuencia de trabajo seria:
    - git add .
    - git commit -m "descripcion significativa"
    - git push
    - git status o git log --oneline de ser necesario
    - Repetimos

15) Una forma mas segura/organizada es usando ramas, _branches_
    - git switch -c nombre-de-la-rama : (crea y cambia a la otra rama)
    - git branch : para consultar que ramas hay y en cual estoy parado
    - git switch nombre-de-la-rama : para cambiar a la rama "nombre-de-la-rama"
    - Trabajamos en la rama que vamos a fucionar con la rama main
    - git push -u origin nombre-de-la-rama : para subir la rama al repositorio remoto
    - git switch main (o otra rama a fusionar)
    - git merge nombre-de-la-rama : para fusionar con la rama main
    - git branch -d nombre-de-la-rama : en caso de querer borrar esta ramas
