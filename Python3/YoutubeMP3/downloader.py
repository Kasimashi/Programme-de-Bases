import yt_dlp

def download_best_mp3(youtube_url, output_path="downloads/"):
    ydl_opts = {
        'format': 'bestaudio/best',
        'outtmpl': f'{output_path}/%(title)s.%(ext)s',
        'postprocessors': [
            {
                'key': 'FFmpegExtractAudio',
                'preferredcodec': 'mp3',
                'preferredquality': '320',
            },
            {
                'key': 'FFmpegMetadata',
            },
            {
                'key': 'EmbedThumbnail',
            },
        ],
        'writethumbnail': True,              # Télécharge la miniature pour l'inclure
        'postprocessor_args': ['-ar', '44100'],  # Qualité CD
        'prefer_ffmpeg': True,
        'keepvideo': False,
        'quiet': False,
        'nooverwrites': True,
        'clean_infojson': True,              # Ne garde pas les fichiers .info.json
        'final_ext': 'mp3',                  # S'assure que seule l'extension mp3 reste
    }

    with yt_dlp.YoutubeDL(ydl_opts) as ydl:
        ydl.download([youtube_url])

# 🔥 Exemple d'utilisation :
download_best_mp3("https://www.youtube.com/watch?v=-yj5qIvrJtQ&list=PL4GINnHGqe7ia-7vjv1OoWYjKyFPJvoRl&index=1")
