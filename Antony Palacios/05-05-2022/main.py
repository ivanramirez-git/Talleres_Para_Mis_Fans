#Importando librerias
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans

#Importando base de datos
eps=pd.read_csv("../data/eps.csv",nrows=30)

eps

#Tipos de datos
eps.dtypes

#Imprime base de datos con valores null
eps.dropna()

#Convirtiendo los espacios sin diligenciar en null
eps.Codigo_EPS_Destino.replace("SIN DATO",np.nan,inplace=True)
eps.Razon_Social_Destino.replace("SIN DATO",np.nan,inplace=True)
eps.Regimen_Destino.replace("SIN DATO",np.nan,inplace=True)
eps.DPT_Destino.replace("SIN DATO",np.nan,inplace=True)
eps.Municipio_Destino.replace("SIN DATO",np.nan,inplace=True)

#Ordenanmiento la base de datos sin espacios null
eps.dropna(inplace=True)

#Borro las casillas que no voy a utilizar
eps.drop(["DPT_Origen","Municipio_Origen","Municipio_Destino","Razon_Social_Destino","RangoEdad",
"Fecha_Novedad"],axis=1,inplace=True)

eps[0:5]

#Aplicamos agrupamiento a las columnas seleccionadas
eps_dummies=pd.get_dummies(eps[["Nombre","Codigo_EPS_Origen","Regimen_Origen","SEXO"]])

eps=pd.concat([eps,eps_dummies],axis=1)

eps[0:2]

#asignando a un nuevo dataframe solo las columnas agrupadas con dumies borrando las principales
epsn=eps.drop(["Nombre","Codigo_EPS_Origen","Razon_Social_Origen","Regimen_Origen","Codigo_EPS_Destino",
"Regimen_Destino","DPT_Destino","SEXO"],axis=1)

epsn=KMeans(n_clusters=5).fit(epsn)
epsn.labels_