import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

df = pd.read_csv("tempos.csv")

fig, axes = plt.subplots(1, 3, figsize=(18, 6))
fig.suptitle("Análise de Algoritmos — Tempo vs. Tamanho do Vetor", fontsize=14, fontweight="bold")

def fmt_k(x, _):
    return f"{int(x/1000)}k"

# ── Gráfico 1: Busca Sequencial vs Binária ──────────────────────────────────
ax = axes[0]
busca = df[df["algoritmo"].isin(["sequencial", "binaria"])]
cores  = {"sequencial": "#3266ad", "binaria": "#d85a30"}
estilos = {"existe": "-o", "aleatorio": "--s"}

for algo in ["sequencial", "binaria"]:
    for caso in ["existe", "aleatorio"]:
        d = busca[(busca["algoritmo"] == algo) & (busca["caso"] == caso)].sort_values("tamanho")
        ax.plot(d["tamanho"], d["tempo_s"],
                estilos[caso], color=cores[algo], linewidth=2, markersize=5,
                label=f"{algo} ({caso})")

ax.set_title("Busca Sequencial vs. Binária")
ax.set_xlabel("Tamanho do vetor (n)")
ax.set_ylabel("Tempo (s)")
ax.xaxis.set_major_formatter(ticker.FuncFormatter(fmt_k))
ax.legend(fontsize=8)
ax.grid(True, linestyle="--", alpha=0.4)

# ── Gráfico 2: Vetor vs Lista ────────────────────────────────────────────────
ax = axes[1]
vl = df[df["algoritmo"].isin(["vetor", "lista"])]
cores2 = {"vetor": "#3266ad", "lista": "#639922"}

for algo in ["vetor", "lista"]:
    for caso in ["existe", "aleatorio"]:
        d = vl[(vl["algoritmo"] == algo) & (vl["caso"] == caso)].sort_values("tamanho")
        ax.plot(d["tamanho"], d["tempo_s"],
                estilos[caso], color=cores2[algo], linewidth=2, markersize=5,
                label=f"{algo} ({caso})")

ax.set_title("Busca Sequencial: Vetor vs. Lista")
ax.set_xlabel("Tamanho do vetor (n)")
ax.set_ylabel("Tempo (s)")
ax.xaxis.set_major_formatter(ticker.FuncFormatter(fmt_k))
ax.legend(fontsize=8)
ax.grid(True, linestyle="--", alpha=0.4)

# ── Gráfico 3: Ordenação ─────────────────────────────────────────────────────
ax = axes[2]
ord_algos = ["bubble", "insertion", "selection", "merge", "quick"]
cores3 = {"bubble": "#d85a30", "insertion": "#3266ad", "selection": "#639922",
          "merge": "#854f0b", "quick": "#533ab7"}

for algo in ord_algos:
    d = df[(df["algoritmo"] == algo)].sort_values("tamanho")
    ax.plot(d["tamanho"], d["tempo_s"],
            "-o", color=cores3[algo], linewidth=2, markersize=5,
            label=algo.title())

ax.set_title("Algoritmos de Ordenação")
ax.set_xlabel("Tamanho do vetor (n)")
ax.set_ylabel("Tempo (s)")
ax.xaxis.set_major_formatter(ticker.FuncFormatter(fmt_k))
ax.legend(fontsize=8)
ax.grid(True, linestyle="--", alpha=0.4)

plt.tight_layout()
plt.savefig("grafico_algoritmos.png", dpi=150, bbox_inches="tight")
plt.show()