# Inicialicazao
clear
reset
set key off

#Configuracoes de saida: inclui formato de exportacao, tamanho do grafico,
# fontes utilizadas e nome do arquivo de saida

# Exportacao para o formato .png
set terminal png size 640,480 enhanced font 'Helvetica,12'
set output 'histograma.png'

# Exportacao para o formato .jpg
set terminal jpeg size 640,480 enhanced font 'Helvetica' 12
set output 'histograma.jpg'

# Exportaao para o formato .svg
# set terminal svg size 640,480 enhanced background rgb 'white' fname 'Helvetica' fsize
# 14 butt solid
# set output 'histograma.svg'

# Titulo do gráfico
set title 'Total de nascidos vivos no RN (1994-2014)'

# Configurações do eixo horizontal
set xrange[1994:2014]                   # Faixa de valores
set xtics 1                             #Salto entre valores
set xtic rotate by -45 scale 0          #Rotaçao dos rótulos

# Configurações do eixo vertical
set yrange[0:80000]                     # Faixa de valores

# Seleção do tipo de gráfico a ser gerado (histograma)
set style data histogram
set style histogram clustered gap 1
set style fill solid border -1          # Preenchimento e contorno
set linetype 1 lc rgb 'green'           # Cor 
set boxwidth 0.6                        # Largura das barras verticais

# Plotagem do gráfico
# Os dados a serem plotados constam no arquivo totais.dat
plot 'totais.dat' using 1:2 title '' smooth freq with boxes