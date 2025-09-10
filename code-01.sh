#!/bin/bash
# Script para gerar relatório de informações do sistema

echo "===================================="
echo " RELATÓRIO DO SISTEMA LINUX"
echo "===================================="
echo

# Espaço em disco
echo "[+] Espaço em Disco:"
df -h
echo

# Memória RAM
echo "[+] Memória RAM e Swap:"
free -h
echo

# Processos
echo "[+] Quantidade de Processos em Execução:"
pgrep -c .
echo
echo "[+] Top 10 processos por uso de CPU:"
ps aux --sort=-%cpu | head -n 11
echo

# CPU
echo "[+] Informações da CPU:"
lscpu | head -n 10
echo

# Uptime
echo "[+] Uptime:"
uptime
echo

# Sistema de arquivos
echo "[+] Sistemas de Arquivos Montados:"
mount | head -n 10
echo

# Kernel e SO
echo "[+] Kernel e Sistema Operacional:"
uname -a
hostnamectl
echo

# Usuários
echo "[+] Usuários logados:"
who -u
echo

echo "===================================="
echo " FIM DO RELATÓRIO"
echo "===================================="
